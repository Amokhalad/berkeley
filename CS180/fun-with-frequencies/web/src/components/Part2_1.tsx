import React from 'react';
import { BlockMath, InlineMath } from 'react-katex';

const Part2: React.FC = () => {
    return (
        <section id="part2.1">
            <h2>Image Sharpening</h2>


            <p>
                In this section, we explore the unsharp masking technique to sharpen images by enhancing their high-frequency components. High frequencies in an image correspond to rapid changes in intensity, which are typically found at edges and fine details.
            </p>
            <p>
                We start with the original image of the Taj Mahal:
            </p>
            <figure>
                <img src="./output_pt2_1/taj.jpg" alt="Original Taj Mahal" className="img-fluid" />
                <figcaption><strong>Figure 1:</strong> Original image of the Taj Mahal.</figcaption>
            </figure>
            <p>
                To obtain the high-frequency/details components, we perform the following steps:
            </p>
            <ol>
                <li>
                    <strong>Blur the original image:</strong> We apply a Gaussian blur to the image to remove high-frequency content, resulting in a low-frequency (smooth/blurred) version of the image.
                </li>
                <li>
                    <strong>Extract high frequencies:</strong> We subtract the blurred image from the original image to isolate the high-frequency components.
                </li>
                <li>
                    <strong>Add scaled high frequencies back to the original image:</strong> By adding a scaled version of the high frequencies to the original image, we enhance the details and sharpness.
                </li>
            </ol>
            <p>
                Mathematically, the process can be expressed as:
            </p>
            <BlockMath math={`\\text{Blurred Image} = X \\ast G`} />
            <BlockMath math={`\\text{Details} = X - \\text{Blurred Image}`} />
            <BlockMath math={`\\text{Sharpened Image} = X + \\alpha \\times \\text{Details}`} />
            <p>
                Where <InlineMath math='X' /> is the original image, <InlineMath math='G' /> is the gaussian kernel, and <InlineMath math={`\\alpha`} /> is the scaling factor for the high frequencies. In our case, we set <InlineMath math={`\\alpha = 2`} />. Below are the results at each step of the sharpening process:
            </p>

            <figure>
                <div className="images-container">
                    <div className="image-container img-md">
                        <img src="./output_pt2_1/lowpass-taj.jpg" alt="Blurred Image" className="img-fluid" />
                        <figcaption><strong>Figure 2:</strong> Blurred image after applying Gaussian filter.</figcaption>
                    </div>

                    <div className="image-container img-md">
                        <img src="./output_pt2_1/highpass-taj.jpg" alt="High Frequencies" className="img-fluid" />
                        <figcaption><strong>Figure 3:</strong> High-frequency components extracted from the image.</figcaption>
                    </div>

                    <div className="image-container img-md">
                        <img src="./output_pt2_1/sharpened-taj.jpg" alt="Sharpened Image" className="img-fluid" />
                        <figcaption><strong>Figure 4:</strong> Sharpened image after adding scaled high frequencies back to the original image.</figcaption>
                    </div>
                </div>
            </figure>
            <p>
                As observed, the sharpened image has enhanced details compared to the original image. The architectural features and textures of the Taj Mahal are more pronounced, making the image appear crisper.
            </p>

            <p>
                If we'd like, we can obtain the sharpened image with a single convolution operation, which is called the unsharp mask filter. With a bit of math manipulation, we can express the unsharp mask filter as:
            </p>
            <BlockMath math={`\\text{Sharpened Image} = \\text{X} * ((1 + \\alpha)e - \\alpha G)`} />
            <p>
                Where <InlineMath math={`e`} /> is the unit impulse and <InlineMath math={`G`} /> is the Gaussian filter kernel.
            </p>


            <h3>Sunset Landscape</h3>
            <p>
                The sunset landscape image below was sharpened using <code>alpha = 3.0</code> and a smaller kernel size of <code>kernel_size=3</code>. As shown below, the clouds and ripples in the water are emphasized by the sharpening procedure.
            </p>

            <figure>
                <div className="image-container img-md">
                    <img src="./output_pt2_1/highpass-cool-landscape.jpg" alt="Original Sunset Landscape" className="img-fluid" />
                    <figcaption><strong>Figure 5:</strong> Details of the sunset landscape.</figcaption>
                </div>
            </figure>

            <figure>
                <div className="images-container">
                    <div className="image-container img-md">
                        <img src="./output_pt2_1/cool-landscape.jpg" alt="Original Sunset Landscape" className="img-fluid" />
                        <figcaption><strong>Figure 6:</strong> Original sunset landscape image.</figcaption>
                    </div>

                    <div className="image-container img-md">
                        <img src="./output_pt2_1/sharpened-cool-landscape.jpg" alt="Sharpened Sunset Landscape" className="img-fluid" />
                        <figcaption><strong>Figure 7:</strong> Sharpened sunset landscape image.</figcaption>
                    </div>
                </div>
            </figure>



            <h3>Sharpening a Blurry Image</h3>
            <p>Lets evaluate the sharpening process on a blurry image. This image below is a blurry image captured of the city streets. The image of the streets was first blurred using a <code>kernel_size=3</code> and then sharpened using <code>alpha = 5.0</code>. As shown below, most of the edges of the buildings and cars are more prominent after the sharpening procedure.</p>
            <figure>
                <div className="images-container">
                    <div className="image-container img-md">
                        <img src="./output_pt2_1/blurry-image.jpg" alt="Original Blurry Image" className="img-fluid" />
                        <figcaption><strong>Figure 8:</strong> Original blurry image.</figcaption>
                    </div>

                    <div className="image-container img-md">
                        <img src="./output_pt2_1/sharpened-blurry-image.jpg" alt="Blurred Image" className="img-fluid" />
                        <figcaption><strong>Figure 9:</strong> Sharpened Image</figcaption>
                    </div>
                </div>
            </figure>
        </section>
    );
};

export default Part2;
