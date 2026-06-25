import React, { useEffect, useState } from 'react';

// Define ImageData interface
interface ImageData {
    color: string;
    red_shift: number[];
    green_shift: number[];
}

const Results: React.FC = () => {
    const [imageData, setImageData] = useState<ImageData[]>([]);

    useEffect(() => {
        const fetchImageData = async () => {
            try {
                const response = await fetch('./imageData.json');
                if (!response.ok) {
                    throw new Error('Failed to load image data');
                }
                const data: ImageData[] = await response.json();
                setImageData(data);
            } catch (error) {
                console.error('Error loading image data:', error);
            }
        };

        fetchImageData();
    }, []);

    return (
        <section id="results">
            <h2>Results</h2>
            <p>
                Below are the results showcasing the images after the procedure is done. Each image has been adjusted to correct color channel misalignments and automatically cropped to remove the irregular boarders. Below each image, you’ll see the amount of shift applied to the red and green channels during the alignment process. The <strong className="text-danger">Red Shift</strong> shows the adjustments made to the red channel, while the <strong className="text-success">Green Shift</strong> shows the corresponding changes to the green channel.
            </p>

            <table className="table">
                <tbody>
                    {imageData.map((data, index) => {
                        // Start a new row every two images
                        if (index % 2 === 0) {
                            return (
                                <tr key={index}>
                                    <td className="text-center">
                                        <div className="d-flex flex-column align-items-center">
                                            <img
                                                src={data.color}
                                                alt={`Image ${index + 1}`}
                                                className="img-fluid img-fluid-custom"
                                                loading="lazy"
                                            />
                                            <p className="text-center mt-2">
                                                <strong className="text-danger">Red Shift:</strong> [{data.red_shift.join(', ')}] |
                                                <strong className="text-success"> Green Shift:</strong> [{data.green_shift.join(', ')}]
                                            </p>
                                        </div>
                                    </td>
                                    {/* Check if there's another image to display, otherwise, leave an empty cell */}
                                    {imageData[index + 1] ? (
                                        <td className="text-center">
                                            <div className="d-flex flex-column align-items-center">
                                                <img
                                                    src={imageData[index + 1].color}
                                                    alt={`Image ${index + 2}`}
                                                    className="img-fluid img-fluid-custom"
                                                    loading="lazy"
                                                />
                                                <p className="text-center mt-2">
                                                    <strong className="text-danger">Red Shift:</strong> [{imageData[index + 1].red_shift.join(', ')}] |
                                                    <strong className="text-success"> Green Shift:</strong> [{imageData[index + 1].green_shift.join(', ')}]
                                                </p>
                                            </div>
                                        </td>
                                    ) : (
                                        <td></td> // Leave the second column empty if there is an odd number of images
                                    )}
                                </tr>
                            );
                        }
                        return null;
                    })}
                </tbody>
            </table>
        </section>
    );
};

export default Results;
