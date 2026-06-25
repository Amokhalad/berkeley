import React from 'react';

const About: React.FC = () => {
    return (
        <section id="about">
            <h2>Introduction</h2>
            <p>
                This project explores the fascinating world of image processing by delving into filters and frequencies. We begin with building intuitions about 2D convolutions and filtering techniques.
            </p>
            <p>
                <strong>Part 1: Fun with Filters</strong><br />
                We start by implementing finite difference operators to compute the partial derivatives of images. This helps in understanding edge detection and image gradients. We then move on to the Derivative of Gaussian (DoG) filters to reduce noise and improve edge detection results.
            </p>
            <p>
                <strong>Part 2: Fun with Frequencies</strong><br />
                In this section, we experiment with image "sharpening" using unsharp masking techniques. We also create hybrid images that change interpretation based on viewing distance, blending the high-frequency component of one image with the low-frequency component of another. Furthermore, we explore multi-resolution blending to seamlessly blend images using Gaussian and Laplacian stacks, culminating in creative outputs like the "oraple" (a blend of an orange and an apple).
            </p>
            <p>
                Through this project, we aim to demonstrate practical applications of image processing while encouraging creative experimentation with visual content.
            </p>
        </section>
    );
};

export default About;
