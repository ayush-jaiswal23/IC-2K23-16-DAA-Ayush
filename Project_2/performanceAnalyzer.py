import time
import tracemalloc
import numpy as np
import matplotlib.pyplot as plt

MODEL_TRANSFORMS = {
    'O(1)': lambda n: np.ones_like(n, dtype=float),
    'O(log N)': lambda n: np.log2(n),
    'O(N)': lambda n: n,
    'O(N log N)': lambda n: n * np.log2(n),
    'O(N^2)': lambda n: n ** 2,
    'O(N^3)': lambda n: n ** 3
}

def fit_linear(x_transformed, y):
    """
    Fits y = a * x_transformed + b using Ordinary Least Squares.
    Returns slope (a), intercept (b), and R-squared score.
    """
    # Linear fit: y = a*x + b
    popt = np.polyfit(x_transformed, y, 1)
    a, b = popt[0], popt[1]

    # Calculate R-squared (Coefficient of Determination)
    predictions = a * x_transformed + b
    ss_res = np.sum((y - predictions) ** 2)
    ss_tot = np.sum((y - np.mean(y)) ** 2)
    
    # Handle zero division if all y values are identical
    r2 = 1 - (ss_res / ss_tot) if ss_tot > 0 else 0.0
    
    return a, b, r2

class AlgorithmAnalyzer:
    def __init__(self, target_function, input_generator):
        self.func = target_function
        self.gen = input_generator
        self.sizes = []
        self.times = []
        self.memory = []

    def run_experiments(self, sizes, repetitions=3):
        """Executes the function across various N, measuring runtime and peak memory."""
        self.sizes = np.array(sizes, dtype=float)
        self.times = []
        self.memory = []

        print(f"Running experiments for '{self.func.__name__}'...")
        for n in sizes:
            exec_times = []
            peak_mems = []
            
            for _ in range(repetitions):
                data = self.gen(int(n))
                
                tracemalloc.start()
                start_time = time.perf_counter()
                
                self.func(data)
                
                end_time = time.perf_counter()
                _, peak_mem = tracemalloc.get_traced_memory()
                tracemalloc.stop()

                exec_times.append(end_time - start_time)
                peak_mems.append(peak_mem / 1024)  # KB

            self.times.append(np.median(exec_times))
            self.memory.append(np.median(peak_mems))
            print(f"  N = {int(n):<8} | Time = {self.times[-1]:.6f}s | Memory = {self.memory[-1]:.2f} KB")

        self.times = np.array(self.times)
        self.memory = np.array(self.memory)

    def analyze_complexity(self, metric='time'):
        """
        Evaluates theoretical complexity fits using R^2 score.
        The model closest to 1.0 is selected as the best fit.
        """
        y_data = self.times if metric == 'time' else self.memory
        best_model = None
        best_r2 = -float('inf')
        fitted_results = {}

        for name, transform_func in MODEL_TRANSFORMS.items():
            x_trans = transform_func(self.sizes)
            a, b, r2 = fit_linear(x_trans, y_data)

            fitted_results[name] = (transform_func, a, b, r2)

            if r2 > best_r2:
                best_r2 = r2
                best_model = name

        return best_model, fitted_results

    def plot_results(self):
        """Plots experimental scatter points alongside linearized theoretical models."""
        fig, axes = plt.subplots(1, 2, figsize=(14, 5))
        dense_n = np.linspace(min(self.sizes), max(self.sizes), 200)

        # 1. Time Plot
        best_time, time_fits = self.analyze_complexity(metric='time')
        axes[0].scatter(self.sizes, self.times, color='red', label='Experimental Data', zorder=5)

        for name, (transform, a, b, r2) in time_fits.items():
            is_best = (name == best_time)
            y_pred = a * transform(dense_n) + b
            axes[0].plot(
                dense_n, y_pred, 
                label=f"{name} (R²={r2:.3f})", 
                linestyle='-' if is_best else '--', 
                alpha=1.0 if is_best else 0.4, 
                lw=2.5 if is_best else 1.0
            )

        axes[0].set_title(f"Time Complexity (Best Fit: {best_time})", fontweight='bold')
        axes[0].set_xlabel("Input Size (N)")
        axes[0].set_ylabel("Execution Time (seconds)")
        axes[0].grid(True, linestyle=':', alpha=0.6)
        axes[0].legend()

        # 2. Memory Plot
        best_mem, mem_fits = self.analyze_complexity(metric='memory')
        axes[1].scatter(self.sizes, self.memory, color='blue', label='Experimental Data', zorder=5)

        for name, (transform, a, b, r2) in mem_fits.items():
            is_best = (name == best_mem)
            y_pred = a * transform(dense_n) + b
            axes[1].plot(
                dense_n, y_pred, 
                label=f"{name} (R²={r2:.3f})", 
                linestyle='-' if is_best else '--', 
                alpha=1.0 if is_best else 0.4, 
                lw=2.5 if is_best else 1.0
            )

        axes[1].set_title(f"Space Complexity (Best Fit: {best_mem})", fontweight='bold')
        axes[1].set_xlabel("Input Size (N)")
        axes[1].set_ylabel("Peak Memory (KB)")
        axes[1].grid(True, linestyle=':', alpha=0.6)
        axes[1].legend()

        plt.tight_layout()
        plt.show()

if __name__ == "__main__":
    def bubble_sort(arr):
        n = len(arr)
        for i in range(n):
            for j in range(0, n - i - 1):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
        return arr

    def random_array(n):
        return list(np.random.randint(0, 10000, size=n))

    # Test with Bubble Sort (Expect O(N^2) time, O(N) memory allocation)
    analyzer = AlgorithmAnalyzer(bubble_sort, random_array)
    analyzer.run_experiments(sizes=[200, 400, 800, 1600, 3200])
    analyzer.plot_results()