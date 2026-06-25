// Header.tsx
import React from 'react';

const Header: React.FC = () => {
    return (
        <section id="header" className="py-5">
            <div className="container">
                <header className="text-center mb-4">
                    <h1 className="display-4">Fun with Frequencies</h1>
                    <div className="d-flex justify-content-center gap-3">
                        <p className="mb-0 text-muted">By <span className="fw-semibold">Mokhalad Aljuboori</span></p>
                        <p className="mb-0 text-muted">Created on <span className="fw-semibold">September 22, 2024</span></p>
                    </div>
                </header>
            </div>
        </section>
    );
};

export default Header;
