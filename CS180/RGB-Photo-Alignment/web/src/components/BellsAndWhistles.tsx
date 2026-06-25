import React from 'react';

const BellsAndWhistles: React.FC = () => {

    return (
        <section id="extra">
            <h2>Bells and Whistles</h2>
            <div>
                <h3>Auto Cropping</h3>
                <p>
                    Automatic cropping is done by removing the margins based on the row/column with the lowest consistent variance in the margins. The core idea is that borders or margins tend to have uniform colors, resulting in a lower variance in pixel values along the rows and columns. By measuring this variance, we can detect the areas of the image that are likely part of the border.
                </p>
                <p>
                    Instead of just picking the area with the absolute smallest variance (which may be influenced by noise or small changes in lighting), the algorithm identifies the "deepest" margin where the variance remains low. This approach prevents premature cropping that could cut into the actual content of the image due to small, inconsistent variations.
                </p>
                <p>
                    The process is implemented as follows:
                </p>
                <ul>
                    <li>First, the image is converted to normalized pixel values if necessary, ensuring that all pixel values lie within a range of [0, 1] for consistent variance calculations.</li>
                    <li>The image is divided into regions along the top, bottom, left, and right margins, which are determined as a fraction of the image's width or height (based on a default margin fraction of 5%).</li>
                    <li>For each of these margins, the variance in pixel values across all three color channels (RGB) is calculated along the rows and columns.</li>
                    <li>The algorithm then finds the deepest point (in pixels) within each margin where the variance exceeds a set threshold. This variance threshold helps define where the border ends and the actual content of the image begins. For example, rows or columns with very low variance are considered part of the border, while higher variance indicates that content has been reached.</li>
                    <li>Once the points of transition are determined for the top, bottom, left, and right margins, the image is cropped to remove the detected border areas while keeping the essential content intact.</li>
                </ul>
                <p>
                    This approach ensures that the image is automatically cropped without cutting into important parts of the content, leaving a clean and balanced result by intelligently removing the margins with low variance.
                </p>
            </div>

            <div>
            </div>
        </section>
    );
};

export default BellsAndWhistles;
