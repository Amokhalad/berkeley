// Method.tsx
import React from 'react';
import { BlockMath } from 'react-katex';

const Method: React.FC = () => {
    return (
        <section id="method">
            <h2>Method</h2>
            <p>Below is an overview of the steps involved in the image alignment process:</p>
            <ol>
                <li>Splitting the image</li>
                <li>Cropping the images</li>
                <li>Aligning the RGB channels</li>
            </ol>

            <div>
                <h3>Step 1: Splitting the Image into RGB Channels</h3>
                <p>
                    The first step involves dividing the image into its three color channels: red, green, and blue. This is done by splitting the image into regions based on its height, dividing by three, and assigning each region to its respective color channel.
                </p>
            </div>

            <div>
                <h3>Step 2: Cropping the Images</h3>
                <p>
                    The original Prokudin-Gorskii plates often contain black and white borders, which can interfere with the alignment process. To eliminate this issue, we remove 20% of the pixels from each side of the image. This ensures that alignment calculations are performed only on the internal pixels, which speeds up the process and improves accuracy by focusing on the meaningful parts of the image.
                </p>
            </div>

            <div>
                <h3>Step 3: Aligning the RGB Channels</h3>
                <p>
                    Alignment is achieved by determining the displacement vector <code>(dx, dy)</code> that best shifts one channel to align with another. In this project, both the green and red channels are aligned to the blue channel.
                </p>

                <p>
                    A simple brute-force method is employed, which searches a fixed range of displacements and scores each alignment using an image matching metric. For low-resolution images, a search window of <code>[-15, +15]</code> and the normalized cross-correlation (NCC) metric provide satisfactory results. Below are some examples of aligned images:
                </p>

                <figure className="image-gallery">
                    <div className="images-container">
                        <div className="img-md image-container">
                            <img src="./figures/monastery.jpg" alt="Aligned Monastery Image" className='img-fluid' />
                        </div>
                        <div className="img-md image-container">
                            <img src="./figures/tobolsk.jpg" alt="Aligned Harvesters Image" className='img-fluid' />
                        </div>
                    </div>
                    <figcaption>
                        <b>Figure 2</b>: Aligned blue, green, and red channels using the brute-force method.
                    </figcaption>
                </figure>

                <p>
                    The NCC metric is calculated as the inner product of two normalized vector representations of the color channels:
                </p>
                <BlockMath>
                    {`\\text{NCC}(\\bm{c_1}, \\bm{c_2}) = \\frac{\\bm{c_1}}{\\|\\bm{c_1}\\|} \\cdot \\frac{\\bm{c_2}}{\\|\\bm{c_2}\\|}`}
                </BlockMath>
                <p>
                    When the channels are perfectly aligned, the NCC value will be 1; if they are completely misaligned, the value will be 0. The displacement vector that yields the highest NCC value is selected as the best alignment.
                </p>

                <h4>Image Pyramid</h4>
                <p>
                    While brute-force alignment works well for low-resolution images, it becomes inefficient for high-resolution scans. As image resolution increases, the displacement window must also grow, resulting in higher computational costs. The complexity of the brute-force method is:
                </p>
                <BlockMath>
                    {`O(D^2 \\cdot W H)`}
                </BlockMath>
                <p>
                    Here, <code>D</code> is the window size, and <code>W</code> and <code>H</code> are the image dimensions.
                </p>

                <p>
                    To improve efficiency, we employ an image pyramid approach. This method generates a series of progressively lower-resolution images by applying a blur and downsampling (by half) until the image size goes below 300 pixels. The alignment begins at the lowest resolution, using the result to guide alignment at higher levels, until the full-resolution image is aligned.
                </p>

                <p>
                    This approach reduces the runtime complexity to:
                </p>
                <BlockMath>
                    {`O(\\log(\\min(W,H)) \\cdot W H)`}
                </BlockMath>
                <p>
                    The logarithmic factor reflects the decrease in pixel count at each level of the pyramid, resulting in faster alignment compared to brute-force methods.
                </p>

                <h4>Edge Detection</h4>
                <p>
                    Despite the success of the pyramid method, some images with intense colors in one channel caused alignment issues.
                </p>

                <figure>
                    <div className="img-md image-container">
                        <img src="./experiments/emir_color.jpg" alt="Misaligned photo due to high intensity colors in red channel" className='img-fluid' />
                    </div>
                    <figcaption><b>Figure 3</b>: Misaligned photo due to high intensity in the red channel.</figcaption>
                </figure>

                <p>
                    To address this, we applied an edge detection algorithm, specifically the <a href="https://en.wikipedia.org/wiki/Canny_edge_detector">Canny edge detector</a>, which improved alignment accuracy by focusing on the image's edges rather than its intensity values. This fixed the alignment issue on all example images.
                </p>

                <figure>
                    <div className='img-md image-container'>
                        <img src="./experiments/emir_edges_r.jpg" alt="Edges of the red channel" className='img-fluid' />
                    </div>
                    <figcaption><b>Figure 4</b>: Edge-detected red channel, leading to successful alignment.</figcaption>
                </figure>

            </div>

        </section >
    );
};

export default Method;
