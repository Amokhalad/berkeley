import './App.css'
import Header from './components/Header'
import About from './components/About'
import Part1 from './components/Part1'
import Part2 from './components/Part2'
// import Results from './components/Results'

function App() {

  return (
    <div className="container">
      <Header />
      <About />
      <Part1 />
      <Part2 />
      {/* <Results /> */}

    </div>
  )
}

export default App
