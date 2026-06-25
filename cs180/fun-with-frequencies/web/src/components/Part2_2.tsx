import React from 'react';

const Part2_2: React.FC = () => {
    return (
        <section id="hybrid-images">
            <h2>Hybrid Images</h2>
            <p>
                In this part, we'll create hybrid images using the approach described in the SIGGRAPH 2006 <a href='http://olivalab.mit.edu/publications/OlivaTorralb_Hybrid_Siggraph06.pdf'>paper</a> by Oliva, Torralba, and Schyns. Hybrid images are a static image that changes in interpretation as a function of the viewing distance. The basic idea is that high frequency tends to dominate perception when it is available, but, at a distance away, only the low frequency (smooth) part of the signal can be seen. By blending the high frequency portion of one image with the low-frequency portion of another, you get a hybrid image that leads to different interpretations at different distances.
            </p>
            <h3>Approach</h3>
            <p>
                The approach to creating hybrid images involves the following steps:
            </p>
            <ol>
                <li>First, we take two images as input, <code>im_lo</code> (to be seen far away) and <code>im_hi</code> (to be seen up close)</li>
                <li>Next we pick to points on each image so that we align them, by rescaling, sheering and rotating.</li>
                <li>Then we compute the low frequencies on the <code>im_lo</code> by convolving with a gaussian filter</li>
                <li>Next we compute the high frequencies on the <code>im_hi</code> by subtracting the low frequencies from the original image</li>
                <li>Finally, we average the low frequencies of <code>im_lo</code> with the high frequencies of <code>im_hi</code> to get the hybrid image</li>
            </ol>

            <p>Lets look at some of my hybrid images:</p>
            <h3>Berk-ford</h3>
            <p>
                Lets blend berkeley and stanford logos. Blurring was performed using <code>sigma_lo=4</code> and <code>sigma_hi=1</code>, with the kernel size of <code>im_lo</code> being 4 times the respective sigma value and the kernel size for <code>im_hi</code> being 2 times the respective sigma value. Looking at the image you should see the berkeley logo. Take a few steps back and you should see the stanford logo.
            </p>

            <figure>
                <div className="images-container">
                    <div className="image-container img-md">
                        <img src="./output_pt2_2/berkeley.jpg" alt="berkeley logo" className='img-fluid' />
                        <figcaption><strong>Figure 13:</strong> Original blurry image.</figcaption>
                    </div>

                    <div className="image-container img-sm">
                        <img src="./output_pt2_2/stanford.jpeg" alt="stanford logo" className='img-fluid' />
                        <figcaption><strong>Figure 14:</strong> Original blurry image.</figcaption>
                    </div>
                </div>
            </figure>

            <figure>

                <div className="image-container img-lg">
                    <img src="./output_pt2_2/hybrid_stanford_berkeley.jpg" alt="hybrid_stanford_berkeley" className="img-fluid" style={{ width: '100%', maxWidth: '600px' }} />
                    <figcaption>Figure 15: Berk-ford</figcaption>
                </div>
            </figure>


            <h3>Donald Harris</h3>
            Blurring was performed using <code>sigma_lo=5</code> and <code>sigma_hi=4</code>, with the kernel size being 4 times the sigma values. Looking at the image you should see Kamila harris. Take a few steps back and you should see Trump.

            <figure>
                <div className="images-container">
                    <div className="image-container img-sm">
                        <img src="./output_pt2_2/trump.jpg" alt="trump mugshot" className='img-fluid' />
                        <figcaption><strong>Figure 10:</strong> Original blurry image.</figcaption>
                    </div>

                    <div className="image-container img-md">
                        <img src="./output_pt2_2/harris.jpg" alt="kamila harris" className='img-fluid' />
                        <figcaption><strong>Figure 11:</strong> Original blurry image.</figcaption>
                    </div>
                </div>
            </figure>

            <figure>
                <div className="image-container img-lg">
                    <img src="./output_pt2_2/hybrid_trump_harris.jpg" alt="" className='img-fluid' />
                    <figcaption><strong>Figure 12:</strong> Hybrid image of Trump and Harris.</figcaption>
                </div>
            </figure>




            <h3>Fourier Transform</h3>
            <p>
                For the Donald trump and kamila harris images, fourier transforms were applied to the original input images, the filtered images <code>im_lo</code> and <code>im_hi</code>, and the final hybrid image, producing the following graphs:
            </p>

            <figure>
                <div className="images-container">
                    <div className="image-container img-sm">
                        <img src="./output_pt2_2/fft_lo.png" alt="FFT of low frequency image" className='img-fluid' />
                        <figcaption><strong>Figure 16:</strong> FFT of low frequency image.</figcaption>
                    </div>

                    <div className="image-container img-sm">
                        <img src="./output_pt2_2/fft_lo_filtered.png" alt="FFT of filtered low frequency image" className='img-fluid' />
                        <figcaption><strong>Figure 18:</strong> FFT of filtered low frequency image.</figcaption>
                    </div>


                </div>
            </figure>

            <figure>
                <div className="images-container">
                    <div className="image-container img-sm">
                        <img src="./output_pt2_2/fft_hi.png" alt="FFT of high frequency image" className='img-fluid' />
                        <figcaption><strong>Figure 17:</strong> FFT of high frequency image.</figcaption>
                    </div>

                    <div className="image-container img-sm">
                        <img src="./output_pt2_2/fft_hi_filtered.png" alt="FFT of filtered high frequency image" className='img-fluid' />
                        <figcaption><strong>Figure 19:</strong> FFT of filtered high frequency image.</figcaption>
                    </div>
                </div>
            </figure>

            <figure>
                <div className="image-container img-lg">
                    <img src="./output_pt2_2/fft_hybrid.png" alt="FFT of hybrid image" className='img-fluid' />
                    <figcaption><strong>Figure 20:</strong> FFT of hybrid image.</figcaption>
                </div>
            </figure>

        </section>


    );
};

export default Part2_2;