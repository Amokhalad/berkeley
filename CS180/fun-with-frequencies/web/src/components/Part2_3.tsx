import React from 'react';

const Part2_3: React.FC = () => {
    return (
        <div>
            <h2>Gaussian and Laplacian Stacks</h2>
            <h3>Approach</h3>
            <p>
                At every level of the Gaussian stack, instead of downsampling, the previous level is blurred using a gaussian kernel to produce the next level. Thus the sizes of the images are the same across all levels. The Laplacian stack <code>l_stack</code> is calculated from the Gaussian stack <code>g_stack</code> as follows:
            </p>
            <code>l_stack[i] = g_stack[i] - g_stack[i+1]</code>

            <p>The last level of the Laplacian stack is directly taken from the last level of the Gaussian stack (the blurriest image).</p>

            <h3>Results</h3>
            <p>From top to bottom, the Laplacian stack images for the apple (left) and orange (right) at levels 0, 1, 2, 3 are shown below. The last image result after blending the orange and apple images.</p>

            <div className="image-container img-lg">
                <img src="./output_pt2_4/blended_stacks.png" alt="" className='img-fluid' />
            </div>
            <div className="image-container">
                <img src="./output_pt2_4/blended_oraple.png" alt="oraple" />
                <figcaption><b>Figure 21</b>: Blended Oraple</figcaption>
            </div>
        </div >
    );
};

export default Part2_3;