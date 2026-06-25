# Data 100: Principles and Techniques of Data Science

    University of California, Berkeley
    Instructors: Lisa Yan, Narges Norouzi
    Lecture: Tue/Thur 11:00am-12:30pm 
    Author: Mokhalad Aljuboori


- [Data 100: Principles and Techniques of Data Science](#data-100-principles-and-techniques-of-data-science)
- [5: Data Cleaning and EDA](#5-data-cleaning-and-eda)
  - [**5.2 Granularity, Scope, and Temporality**](#52granularity-scope-and-temporality)
- [8: Visualization II](#8-visualization-ii)
  - [8.1 Kernel Density Functions](#81-kernel-density-functions)
    - [**Gaussian Kernel**](#gaussian-kernel)
  - [Relationships Between Quantitative Variables](#relationships-between-quantitative-variables)
    - [Scatter plots](#scatter-plots)
    - [Hex Plots and Contour Plots](#hex-plots-and-contour-plots)
  - [8.2 Transformations](#82-transformations)
- [14: Gradient Descent II // Feature Engineering](#14-gradient-descent-ii--feature-engineering)
  - [Gradient Descent in 1 Dimension](#gradient-descent-in-1-dimension)
  - [Multidimensional Gradient Descent](#multidimensional-gradient-descent)
  - [Feature Engineering](#feature-engineering)
    - [**Feature Function:**](#feature-function)
    - [One-Hot Encoding](#one-hot-encoding)
  - [Higher-Order Polynomial](#higher-order-polynomial)
- [15: Cross-Validation / Regularization](#15-cross-validation--regularization)
  - [Cross Validation](#cross-validation)
  - [Hyperparameter Terminology](#hyperparameter-terminology)
  - [**K-Fold Cross Validation**](#k-fold-cross-validation)
  - [Test Sets](#test-sets)
  - [Regularization](#regularization)
    - [L2 Regularization (Ridge)](#l2-regularization-ridge)
    - [L2 Regularization Math](#l2-regularization-math)
- [16: Regularization + Random Variables](#16-regularization--random-variables)
  - [L1 Regularization (Lasso)](#l1-regularization-lasso)
  - [Random Variables and Distributions](#random-variables-and-distributions)
    - [Distribution](#distribution)
    - [Common Random Variables](#common-random-variables)
  - [Expectation And Variance](#expectation-and-variance)
    - [Definition of Expectation](#definition-of-expectation)
    - [Definition of Variance](#definition-of-variance)
  - [Sum of Random Variables](#sum-of-random-variables)
    - [Functions of Multiple Random Variables](#functions-of-multiple-random-variables)
    - [Equal vs. Identically Distributed vs. IID](#equal-vs-identically-distributed-vs-iid)
- [19: Case Study: Climate \& Physical Data](#19-case-study-climate--physical-data)
  - [Keeling Curve](#keeling-curve)
  - [Calculating The Greenhouse Effect](#calculating-the-greenhouse-effect)
    - [Calculate Energy In](#calculate-energy-in)
    - [Calculate Energy Out](#calculate-energy-out)
    - [Energy In = Energy Out: $E\_{in} = E\_{out}$](#energy-in--energy-out-e_in--e_out)
    - [Updated Equation](#updated-equation)
  - [Questions](#questions)

# 5: Data Cleaning and EDA

## **5.2 Granularity, Scope, and Temporality**

The **granularity** of a dataset is the level of detail included in the data. To determine the data’s granularity, ask: what does each row in the dataset represent?

# 8: Visualization II

## 8.1 Kernel Density Functions

### **Gaussian Kernel**

$\alpha$ , known as the **bandwidth** parameter, is the standard deviation of the Gaussian kernel function bell curve.

![Untitled](images/08%20Visualization%20II%209289fd55ed8f475fad9043bb04704e01/Untitled.png)

**Question:** Why does increasing standard deviation $\alpha$, smoothens the density curve, and are easier to understand, but we begin to lose important distributional information?

## Relationships Between Quantitative Variables

### Scatter plots

they are one of the most useful tools in representing the relationship between two quantitative variables. Particularly important in gauging the strength, or correlation between variables.

More over, we can add a “third” dimension to our plot with the `hue` parameter in `seaborn` which adds a categorial/or numerical column encoding to an existing visualization.

_Example below:_

![Untitled](images/images/08%20Visualization%20II%209289fd55ed8f475fad9043bb04704e01/Untitled%201.png)

If we wish to see the relationship strength more clearly, we can use `sns.lmplot` to add a regression line over a scatter plot:

![Untitled](images/images/08%20Visualization%20II%209289fd55ed8f475fad9043bb04704e01/Untitled%202.png)

### Hex Plots and Contour Plots

Since often times scatter plots will suffer from over plotting, we have **Hex Plots. Hex Plots** can be thought of as a two dimensional histogram that shows the joint distribution between two variables. This is particularly useful working with very dense data.

![Untitled](images/08%20Visualization%20II%209289fd55ed8f475fad9043bb04704e01/Untitled%203.png)

The axes are evidently binned into hexagons, which makes the linear relationship easier to decipher. Darker regions generally indicate a higher density of points.

## 8.2 Transformations

It is often times hard to interpret data from visual relationships. The presence of outliers and other statistical anomalies make it hard to interpret data.

**Transformations** are the process of manipulating data to find significant relationships between variables. These are often found by applying mathematical functions to variables that “transform” their range of possible values and highlight some previously hidden associations between data.

Transformations are perhaps most useful to **linearize a relationship** between variables.

Say we want to understand the relationship between healthcare and life expectancy. Intuitively there should be a positive correlation, but upon plotting values from a dataset, we find a non-linear relationship that is somewhat hard to understand. However, applying a logarithmic transformation to both variables - healthcare and life expectancy - results in a scatter plot with a linear trend that we can interpret.

![Untitled](images/08%20Visualization%20II%209289fd55ed8f475fad9043bb04704e01/Untitled%204.png)

![Untitled](images/08%20Visualization%20II%209289fd55ed8f475fad9043bb04704e01/Untitled%205.png)

How did we know that taking the logarithm of both sides would result in a linear relationship? The **Tukey-Mosteller Bulge Diagram** is helpful here. We can use the direction of the bulge in our original data to find the appropriate transformations that will linearize the relationship.

![Untitled](images/08%20Visualization%20II%209289fd55ed8f475fad9043bb04704e01/Untitled%206.png)

It’s important to note that this diagram is not perfect, and some transformations will work better than others. In our case, the bulge lies in quadrant 2, but $log x$ and $log⁡y$ (found in Quadrant 3) were the best.

When a distribution has a long right tail, a log-transformation often does a good job of symmetrizing the distribution. Long right tails are common with variables that have a lower limit on the values.

On the other hand, long left tails are common with distributions of variables that have an upper limit, such as percentages (can't be higher than 100%) and GPAs (can't be higher than 4). That is the case for the literacy rate. Typically taking a power-transformation such as squaring or cubing the values can help symmetrize a left-skewed distribution.

# 14: Gradient Descent II // Feature Engineering

## Gradient Descent in 1 Dimension

Gradient Descent allows us to numerically find a minima of functions.

The idea: nudge $\Theta$ in negative slop direction until $\Theta$ converges.

![Untitled](images/14%20Gradient%20Descent%20II%20Feature%20Engineering%2071e6cacbe47b441eb058b3241f9355fd/Untitled.png)

Note: $f(x)$, the function we’re minimizing is usually a **loss function,** like MSE.

What if $x$ is a vector instead of a single value?

## Multidimensional Gradient Descent

We’ve seen before that we often need to optimize a cost function with respect to several parameters. For example: suppose we try to predict the amount tipped from the bill price.

$\text{tip} = \Theta_0 + \Theta_1 \text{bill}$

The MSE will be a two dimensional loss surface.

$\text{MSE}(\Theta_0\; , \Theta_1) = ...$

We use the same principles as in one dimension, but the difference now is that we need to update guesses for both thetas that minimize a loss function $L(\theta, \Chi , Y)$

![Untitled](images/14%20Gradient%20Descent%20II%20Feature%20Engineering%2071e6cacbe47b441eb058b3241f9355fd/Untitled%201.png)

## Feature Engineering

Feature engineering is the process of transforming the raw features into more information features that can be used in modeling or EDA tasks:

Allows us to model a non-linear relationship.

### **Feature Function:**

### One-Hot Encoding

One way to have regression using non-numeric features is to use **one-hot encoding.**

- Each category of a categorial variable gets its own feature (own column)
  - value = 1 if that category applies to that row
  - value = 0 otherwise.

![Untitled](images/14%20Gradient%20Descent%20II%20Feature%20Engineering%2071e6cacbe47b441eb058b3241f9355fd/Untitled%202.png)

**Now the DataFrame that we’re going to do linear regression on is**

![Untitled](images/14%20Gradient%20Descent%20II%20Feature%20Engineering%2071e6cacbe47b441eb058b3241f9355fd/Untitled%203.png)

## Higher-Order Polynomial

the higher polynomial we use to create the model, we run the risk of **overfitting the data.**

# 15: Cross-Validation / Regularization

## Cross Validation

**Different methods for ensuring the generalizability of our models to unseen data.**

We pick the model that preforms best on data that it hasn’t been trained on.

One way we can have data that our model hasn’t trained on is we could wait for more data (expensive) or we could keep some of our data “secret” from ourselves

**Idea 0: Patience**

Wait for more data to be generated (expensive).

**Idea 1: The Holdout Method**

we could keep some of our data “secret” from ourselves, where the data used to train is called **the **“training set”.**

**Held out data** is often called the “**validation set**” or **“development set”.**

The code below splits data with size 35 into two sets of size 25 (training_set) and 10 (dev set).

```python
from sklearn.utils import shuffle
training_set, validation_set = np.split(shuffle(vehicle_data_sample_35), [25])
```

**note: we shuffle to randomize the data incase there is any bias in the order of the rows.**

![Untitled](images/15%20Cross-Validation%20Regularization%20e7f9432393a2404a8e8ff56f8f0c65ec/Untitled.png)

Note from the diagram above, while the training MSE for high values of polynomial degree k is low, the validation MSE is very high. This means that our model overfits on the training data.

## Hyperparameter Terminology

in machine learning, a **hyperparameter** is a value that controls the learning process itself.

We use:

- the **training set** to select parameters
- the **validation set** to select hyperparameters, or more generally, between different competing models.

**Questions:** what is the difference between a parameter and a hyperparameter?

To determine the quality of a particular hyperparamter:

- Train model on **ONLY** the **training set.\** **Quality** is model’s error on ONLY the validation. We pick the hyperparameter where the model error on the validation set is the smallest.

## **K-Fold Cross Validation**

![Untitled](images/15%20Cross-Validation%20Regularization%20e7f9432393a2404a8e8ff56f8f0c65ec/Untitled%201.png)

We divide the data into different folds where we have k (5 in the diagram above) models, where our validation set in $\text{Model}_i$ is $F_i$ , called the validation fold. We then compute the error on the validation fold, and repeat the this process for all $k$ validation folds.

**The quality of a specific hyper parameter** is the average of the $k$ validation fold errors, reducing bias and variance. The hyperparameter you should pick is ofcourse the one with the lowest quality.

Ultimately, the tradeoff is between $k$ and computation time.

## Test Sets

![Untitled](images/15%20Cross-Validation%20Regularization%20e7f9432393a2404a8e8ff56f8f0c65ec/Untitled%202.png)

## Regularization

### L2 Regularization (Ridge)

Constraint the gradient descent so that our parameters have smaller values.

![Untitled](images/15%20Cross-Validation%20Regularization%20e7f9432393a2404a8e8ff56f8f0c65ec/Untitled%203.png)

**_Question:_** What benefit do we get by constraining the gradient descent?

- We do so to ensure that our model is less complex, reducing the chance of overfitting to the training data, enabling the model to be more generalizable to unseen data.

For small ball size:

- model behaves like a constant model. Can’t actually use our 9 features.
- High **training error,** low variance, high **validation error.**

For very large ball size:

- model behaves like OLS (since ball can contain the OLS)
- **if we have tons of features,** results in overfitting. Low **training error,** high variance, high validation error.

**_Question:_** what is variance?

### L2 Regularization Math

find thetas that minimize MSE **such that $\sum_{j = 1}^{d} \Theta_j^2 \le Q$**

The two problems below are equivalent (out of scope.)

![Untitled](images/15%20Cross-Validation%20Regularization%20e7f9432393a2404a8e8ff56f8f0c65ec/Untitled%204.png)

**Question:** What is $Q$? Is it the radius of the circle? the radius of the circle squared?

![Untitled](images/15%20Cross-Validation%20Regularization%20e7f9432393a2404a8e8ff56f8f0c65ec/Untitled%205.png)

# 16: Regularization + Random Variables

## L1 Regularization (Lasso)

the idea is the same as Rigid, except the constraint is a different shape.

![Untitled](images/16%20Regularization%20+%20Random%20Variables%200575a18290f34f7c8afca12b8d2a25ee/Untitled.png)

![Untitled](images/16%20Regularization%20+%20Random%20Variables%200575a18290f34f7c8afca12b8d2a25ee/Untitled%201.png)

The implementation in sklearn is

```python
from sklearn.linear_model import Lasso
lm = Lasso(alpha=10)
lm.fit(data)
lm.coef_
```

![Untitled](images/16%20Regularization%20+%20Random%20Variables%200575a18290f34f7c8afca12b8d2a25ee/Untitled%202.png)

## Random Variables and Distributions

a **random variable** is a numerical function of the randomness.

- it’s randomness $(X or Y)$ is because the sample was drawn at random
- it’s a variable because the value depends on how the sample came out.
- It’s value on any given draw is called a **realization**
- _Domain (input)_: all random samples of size $n$, all possible outcomes of our random process (all possible samples of size $n$)
- _Range (output):_ number line. ????

$P(X = x) = \dfrac{\# \text{times where X = x}}{
pop.size}$
. the prob of that random variable being equal to $x$

### Distribution

The **distribution** of a random variable $X$ is a descriptoipn of how the totail probability of 100% is split over all the possible values of $X.$

A distribution fully defines a random variable.

- [Questions:](https://www.youtube.com/watch?v=1dnPAV8v930&ab_channel=Data100.instructorsDepartmental)
  **Question 1:** why are the values of x = 5, 7 not possible values of the random variable?
  **Question 2:** How can a random variable be 6 or 8 if the sample size is 3?

Note that that you can calculate the area of the probability distribution histogram like this:

### Common Random Variables

**Bernoulli(p):**

- takes on value 1 with probability p, and 0 with probability 1 - p.
- AKA the “indicator” random variable.

**Binomial(n, p)**

- Number of 1s in ‘n’ independent Bernoulli(p) trials

**Uniform on a finite set** of values

- probability of each value is 1 / (size of set)
- For example, a standard/fair die.

**Uniform** on the unit interval(0, 1):

- Density is flat on (0, 1) and 0 elsewhere.

**Normal($\mu, \sigma^2$)\**

$f(x) = \dfrac{1}{\sqrt{2\pi\sigma^2}}e^{\dfrac{-(x-\mu)^2}{2\sigma^2}}$

## Expectation And Variance

Note there are several ways to describe a random variable:

1. Table of all samples s, $X(s)$
2. Distribution Table $P(X = x)$
3. Or Histogram of the distribution table.

Or we can also summerize the distribution using some numerical functions:

1. **Expectiation:** The “average value” of $X$. $E[X]$
2. **Variance:** The “spread” of $X$. $\text{Var}(X)$

Note, the expectation and variance of a random variable are **numerical summaries** of $X$. They are **numbers** and are NOT random!

- Question
  1. Why are they not random if the input to these functions is random? The input to the random variable is random, and we said that it’s random because the sample was drawn at random.

### Definition of Expectation

The **expectation** of a random variable $X$ is the **weighted average** of the values of $X$ where the weights are the probabilities of the values.

1. One sample at a time. $E[X] = \sum_{\text{all samples } s} X(s) P(s)$
2. One possible value at a time. $\sum_{\text{all possible }x} xP(X=x)$

- Questions:
  1. What does a weighted average mean?
  2. What does $P(s)$ mean? Probability of the sample happening?
  3. Why is this an average if we are not dividing by anything?

### Definition of Variance

Variance is the **expected squared deviation from the expectation** of X.

$Var(X) = E[(X - E[X])^2]$

- The units of the variance are the square of the units of $X.$
- To get back to the right scale, use the standard deviation of $X:$ $SD(X) = \sqrt{Var(X)}$

**Alternate Variance Calculation: more convenient**

$Var(X) = E[X^2] - (E[X])^2$

- Questions
  1. If $X$ is a numerical function, how can use do arithmetic with it without passing into it an input? Is it being treated as a vector?
  2. What does it mean to square $X$? A function.
     1. You square the outcomes. For example, let $X$ be the outcome of a single die roll. Then X can take on values {1, 2, 3, 4, 5, 6}. $X^2$ is just those values squared.
        1. So $E[X^2] = \sum_{x} x^2 P(X=x) = \dfrac{91}{6}$

## Sum of Random Variables

### Functions of Multiple Random Variables

A function of a random variable is also a random variable!

If you create multiple random variables based on your sample…….. then functions of those random variables are also random variables.

For instance, if $X_1, X_2, ..., X_n$ are random variables, then so are all of these:

- max($X_1, X_2, ..., X_n$)
- $X_n^2$
- $\frac{1}{n}\sum_{i=1}^n X_i$

### Equal vs. Identically Distributed vs. IID

Suppose that we have two random variables $X$ and $Y$.

$X$ and $Y$ are **equal** if:

- X(s) = Y(s) for every sample s.
- We write $X = Y$

$X$ and $Y$ are identically distributed if:

- the distribution of $X$ is the same as the distribution of $Y$
- We say “$X$ and $Y$ are equal in distribution”
- If $X = Y$, then $X$ and $Y$ are identically distributed; but the converse is not true.

$X$ and $Y$ are independent and identically distributed (IDD) if:

- $X$ and $Y$ are identically distributed, and
- Knowing the outcome of $X$ does not include your belief of the outcome of $Y$, and vice verse (“$X$ and $Y$ are independent”)






# 19: Case Study: Climate & Physical Data

## Keeling Curve

**What is it:**

![Untitled](images/19%20Case%20Study%20Climate%20&%20Physical%20Data%2025611f7b82d246e28e6a3e6fc5aaa8aa/Untitled.png)

it’s has a cyclic nature because CO2 varies, randomly. You can remake this figure by continously tracking CO2 overtime, instead of taking snap shots of CO2 levels, which some scientists suggested.

## Calculating The Greenhouse Effect

Goal 1: Cauclate how the temperature is changing with increasing CO2.

$E_{in} = E_{out}$. → Energy absored from the sub = Energy emitted

How does CO2 affect this?

**A)** The sun emits radiation that is abosrbed by the Earth (~30% is reflected by clounds, ice/snow, desert, that is the **albedo**).

**B)** The earth emits radiation according to Stephan-Boltzman’s Law: the rate that a body emits radiation (per unit area) is directly proportional to the body’s absolute temperature to the fourth power (blackbody radiation). → $E_{out} = \sigma T^4$

**Example:** The coils in a lightbulb emmit radiation (make light, turn red) when they are heated.

**C)** The emitted radiation doesn’t all go back into space….

### Calculate Energy In

- The sun emits radiation $\Omega$ absorbed by the earth.

![Untitled](images/19%20Case%20Study%20Climate%20&%20Physical%20Data%2025611f7b82d246e28e6a3e6fc5aaa8aa/Untitled%201.png)

$E_{in} = \text{Energy-In equals the incoming sunlight (W/m}^2\text{) multiplied by the area } (m^2)\\ \text{ to get W}$

$E_{in} =$ incoming sunlight $\times$ area

$E_{in} = \Omega \pi r^2$

**[Albedo](images/19%20Case%20Study%20Climate%20&%20Physical%20Data%2025611f7b82d246e28e6a3e6fc5aaa8aa.md) $(A) =$\** the **fraction (~30% for earth)\** of radiation reflected back to space by the atmosphere

Therefore, the amount that gets through is $(1 - A)$ so inreality the energy that goes into the earth is actually.

$E_{in} = \Omega \pi r^2(1-A)$

### Calculate Energy Out

B) The Earth emits [blackbody radiation](19%20Case%20Study%20Climate%20&%20Physical%20Data%2025611f7b82d246e28e6a3e6fc5aaa8aa.md)

$E_{out}: \text{Energy-Out equals the emitted radiation } W/m^2 \text{ multiplied by the area to get }W$

$E_{out} = \text{Outgoing radiation } \times \text{area}$

$E_{out} = \sigma T^4 4\pi r^2$

### Energy In = Energy Out: $E_{in} = E_{out}$

![Untitled](images/19%20Case%20Study%20Climate%20&%20Physical%20Data%2025611f7b82d246e28e6a3e6fc5aaa8aa/Untitled%202.png)

But following through with this calculating t find the temperature of the Earth we would calculate that the earth is extremeley cold. (~ -16C). Why did we get this number? What’s missing in our calculation? **The green house effect.** Essentially, our equation was for a planet without an atmosphere.

![Untitled](images/19%20Case%20Study%20Climate%20&%20Physical%20Data%2025611f7b82d246e28e6a3e6fc5aaa8aa/Untitled%203.png)

### Updated Equation

![Untitled](images/19%20Case%20Study%20Climate%20&%20Physical%20Data%2025611f7b82d246e28e6a3e6fc5aaa8aa/Untitled%204.png)

The energy reflected back to earth is proportional to the area of the earth since it happens everywhere, times some constant $\Delta E$, a measure of how good is the atmosphere at being a “blanket”.

We can make a (simple, not very good) linear model by collecting data to find $\Delta E$ using only CO2, but note, we can pick other covariats like methane that contributes to the green house effect:

$\Delta E = \theta_0 + \theta_1 ** \text{CO2}$

## Questions

1. Why is $E_{in} = \Omega \pi r^2$? Surface area for a sphere is $4\pi r^2$, so shouldn’t it be $\Omega 2\pi r^2$ since only half of the earth is being hit by the sun?
