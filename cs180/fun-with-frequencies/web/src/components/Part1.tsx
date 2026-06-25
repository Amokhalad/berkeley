import React from 'react';
import { BlockMath, InlineMath } from 'react-katex';

const Part1: React.FC = () => {
    return (
        <section id="part1">
            <h2>Edge Detection with Derivatives</h2>

            {/* Part 1.1 */}
            <h3>1.1: Finite Difference Operator</h3>
            <p>
                In this section, we explore the use of finite difference operators to compute the partial derivatives of an image in the x and y directions. We use the classic "cameraman" image as our test case.
            </p>

            <figure>
                <div className="image-container img-md">
                    <img src="./output_pt1/cameraman.png" alt="Original cameraman image" className="img-fluid" />
                </div>
                <figcaption><strong>Figure 1:</strong> Original "cameraman" image.</figcaption>
            </figure>

            <p>
                The finite difference kernels are defined as:
            </p>
            <BlockMath math={`D_x = \\begin{bmatrix} 1 & -1 \\end{bmatrix}`} />
            <BlockMath math={`D_y = \\begin{bmatrix} 1 \\\\ -1 \\end{bmatrix}`} />

            <p>
                By convolving the image with these kernels, we obtain the gradients along the x and y axes, which highlight vertical and horizontal edges, respectively.
            </p>

            <figure>
                <div className="images-container">
                    <div className="image-container img-md">
                        <img src="./output_pt1/cameraman_dx.png" alt="Gradient in x-direction" className="img-fluid" />
                        <figcaption><strong>Figure 2:</strong> Gradient in x-direction (convolved with <InlineMath math="D_x" />).</figcaption>
                    </div>
                    <div className="image-container img-md">
                        <img src="./output_pt1/cameraman_dy.png" alt="Gradient in y-direction" className="img-fluid" />
                        <figcaption><strong>Figure 3:</strong> Gradient in y-direction (convolved with <InlineMath math="D_y" />).</figcaption>
                    </div>
                </div>
            </figure>

            <p>
                Notice the anti-aliasing, and irregular edges here. We'll fix this later but lets move on for now. Next step is, we compute the gradient magnitude image by combining the x and y gradients using the Euclidean norm. Here, <InlineMath math="I" /> is the image:
            </p>
            <BlockMath math={`\\text{Gradient Magnitude} = \\sqrt{(I * D_x)^2 + =(I * D_y)^2}`} />
            <figure>
                <img src="./output_pt1/cameraman_grad.png" alt="Gradient magnitude image" className="img-fluid" />
                <figcaption><strong>Figure 4:</strong> Gradient magnitude image.</figcaption>
            </figure>

            <p>
                To create a binary edge map to better see the edges and get rid of noise, we threshold the gradient magnitude image. After experimenting with different thresholds, a value of 0.38 was found to produce a good balance between noise suppression and edge preservation.
            </p>
            <figure>
                <img src="./output_pt1/cameraman_grad_bin.png" alt="Binarized edge image" className="img-fluid" />
                <figcaption><strong>Figure 5:</strong> Binarized edge image using a threshold of 65.</figcaption>
            </figure>

            {/* Part 1.2 */}
            <h3>1.2: Derivative of Gaussian (DoG) Filter</h3>
            <p>
                As can be seen above, the finite difference operators are sensitive to noise, resulting in noisy edge maps. To mitigate this, we apply a low pass filter (a blur) by applying a Gaussian filter to the image before computing the gradients. The Gaussian filter blurs the image, reducing noise while preserving important structural features.
                We use a Gaussian kernel with a size of <code>5</code> and a sigma of <code>1</code>. The blurred image is obtained by convolving the original image with the Gaussian kernel:
            </p>
            <figure>
                <img src="./output_pt1/cameraman_blurred.png" alt="Blurred image" className="img-fluid" />
                <figcaption><strong>Figure 6:</strong> Blurred "cameraman" image after Gaussian filtering.</figcaption>
            </figure>

            <p>
                We then apply the finite difference operators to the blurred image to compute the gradients:
            </p>
            <figure>
                <div className="images-container">
                    <div className="image-container img-md">
                        <img src="./output_pt1/cameraman_blurred_dx.png" alt="Gradient in x-direction (blurred)" className="img-fluid" />
                        <figcaption><strong>Figure 7:</strong> Gradient in x-direction of blurred image.</figcaption>
                    </div>
                    <div className="image-container img-md">
                        <img src="./output_pt1/cameraman_blurred_dy.png" alt="Gradient in y-direction (blurred)" className="img-fluid" />
                        <figcaption><strong>Figure 8:</strong> Gradient in y-direction of blurred image.</figcaption>
                    </div>
                </div>
            </figure>

            <p>
                The gradient magnitude image is then computed from these gradients. And after thresholding, we obtain a cleaner edge map with reduced noise. Here are the results below:
            </p>

            <figure>
                <div className="images-container">
                    <div className="image-container img-md">
                        <img src="./output_pt1/cameraman_dog_grad.png" alt="Gradient magnitude image (blurred)" className="img-fluid" />
                        <figcaption><strong>Figure 9:</strong> Gradient magnitude of blurred image.</figcaption>
                    </div>
                    <div className="image-container img-md">
                        <img src="./output_pt1/cameraman_dog_grad_bin.png" alt="Binarized edge image (blurred)" className="img-fluid" />
                        <figcaption><strong>Figure 10:</strong> Binarized edge image of blurred image.</figcaption>
                    </div>
                </div>
            </figure>

            <p>
                Alternatively, we can combine the Gaussian smoothing and differentiation into a single operation by creating Derivative of Gaussian (DoG) filters. We convolve the Gaussian kernel with the finite difference operators to obtain the DoG filters:
            </p>
            <BlockMath math={`\\text{DoG}_x = G * D_x`} />
            <BlockMath math={`\\text{DoG}_y = G * D_y`} />

            <p>
                Applying the DoG filters directly to the original image yields similar results:
            </p>
            <figure>
                <div className="images-container">
                    <div className="image-container img-md">
                        <img src="./output_pt1/cameraman_dog_grad_naive.png" alt="Gradient magnitude using DoG filters" className="img-fluid" />
                        <figcaption><strong>Figure 11:</strong> Gradient magnitude using DoG filters.</figcaption>
                    </div>

                    <div className="image-container img-md">
                        <img src="./output_pt1/cameraman_dog_grad_bin_naive.png" alt="Binarized edge image using DoG filters" className="img-fluid" />
                        <figcaption><strong>Figure 12:</strong> Binarized edge image using DoG filters.</figcaption>
                    </div>
                </div>
            </figure>

            <p>
                Comparing the results, we observe that using the DoG filters produces similar edge detection performance while combining the smoothing and differentiation steps into a single convolution operation.
            </p>
        </section>
    );
};

export default Part1;
