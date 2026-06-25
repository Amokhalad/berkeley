import React from 'react';

const Part2_4: React.FC = () => {
    return (
        <div>
            <h2>Multiresolution Blending</h2>
            <p>In this section, we'll look at some of my amazing creations. The approach is very similar to that in the previous section, except I tweaked the sigma and ksize to be different values.</p>



            <h3>Earth and Mars</h3>
            <figure>
                <div className="image-container img-lg" style={{ width: '800px', height: 'auto' }}>
                    <img src="./output_pt2_4/earth_and_mars.png" alt="earth and mars" className="img-fluid" style={{ width: '100%', height: 'auto' }} />
                </div>
            </figure>

            <h3>Heaven or Hell</h3>

            <figure>
                <div className="image-container img-lg">
                    <img src="./output_pt2_4/heaven_and_hell.png" alt="oraple" className="img-fluid" />
                </div>
                <figcaption>Heaven and Hell</figcaption>
            </figure>

            <p>Here is the stack analysis at each level</p>

            <figure>
                <div className="image-container img-lg" style={{ width: '900px', height: 'auto' }}>
                    <img src="./output_pt2_4/blended_stacks_hevean_hell.png" alt="" className='img-fluid' style={{ width: '100%', height: 'auto' }} />
                </div>
            </figure>
        </div>
    );
};

export default Part2_4;