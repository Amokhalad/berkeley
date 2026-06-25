// App.tsx
import Header from './components/Header'
import About from './components/About'
import Method from './components/Method'
import Results from './components/Results'
import BellsAndWhistles from './components/BellsAndWhistles'

function App() {

  return (
    <div className="container">
      <main>
        <Header />
        <About />
        <Method />
        <BellsAndWhistles />
        <Results />
      </main>
    </div>

  )
}

export default App
