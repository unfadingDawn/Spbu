import numpy as np
from scipy import stats
import matplotlib.pyplot as plt

t = [7124,7132,7104,7102,7151,7163,7156,7115,7110,7128,7146,7093,7093,7139,7142,7109,7150,7118,7158,7078,7096,7100,7088,7157]
t2 = [7104,7102,7113,7085,7090,7086,7094,7105,7109,7103,7082,7107,7111,7092,7100,7085,7092,7104,7103,7104,7150,7125,7099,7109]
plt.hist(t)
plt.show()
print(stats.normaltest(t))
print(stats.shapiro(t))
print(np.mean(t))
print(np.std(t, ddof=1))
print(stats.t.ppf(0.975, df=len(t)-1)*stats.sem(t))
