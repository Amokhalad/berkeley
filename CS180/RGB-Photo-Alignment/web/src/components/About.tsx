// About.tsx
import './About.css';

const About: React.FC = () => {
    return (
        <section id="method">
            <h2>Introduction</h2>
            <p>
                This project focuses on digitally aligning three channels of Prokudin-Gorskii's historic glass plate images to recreate a single cohesive color photograph.
                <a href="https://en.wikipedia.org/wiki/Sergey_Prokudin-Gorsky">Sergey Prokudin-Gorsky</a>, a pioneering photographer, captured monochrome images using red, green, and blue filters in the early 20th century. These glass plates,
                now digitized and made publicly available by the Library of Congress, provide a fascinating
                look into the past, preserving three filtered images side by side.
            </p>
            <p>
                Our goal is to automatically process these glass plate images, align the RGB channels, and crop them to generate a single, full-color image.
                By applying modern image processing techniques, we can efficiently achieve this in an automated fashion, preserving the integrity and vibrancy of
                the original photographs while creating a fast, streamlined workflow.
            </p>

            <figure className="image-gallery">
                <div className="images-container">
                    <div className="image-container">
                        <img className="img-fluid" src="./data/lady.jpg" alt="Prokudin-Gorskii's Church Image" />
                    </div>
                    <div className="image-container">
                        <img className="img-fluid" src="./data/emir.jpg" alt="Prokudin-Gorskii's Emir Image" />
                    </div>
                    <div className="image-container">
                        <img className="img-fluid" src="./data/harvesters.jpg" alt="Prokudin-Gorskii's Harvesters Image" />
                    </div>
                    <div className="image-container">
                        <img className="img-fluid" src="./data/icon.jpg" alt="Prokudin-Gorskii's Icon Image" />
                    </div>
                </div>
                <figcaption>
                    <b>Figure 1: Original Prokudin-Gorskii Photo Collection plates</b>. Each plate contains three images corresponding to the blue, green, and red channels,
                    respectively from top to bottom. These channels are aligned to produce full-color images.
                </figcaption>
            </figure>
        </section>
    );
};

export default About;
