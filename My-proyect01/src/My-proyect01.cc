// -*- tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
// vi: set et ts=4 sw=2 sts=2:

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include <iostream>
#include <dune/common/parallel/mpihelper.hh> // An initializer of MPI
#include <dune/common/exceptions.hh> // We use exceptions

int main(int argc, char** argv)
{
  try{
    // Maybe initialize MPI
    Dune::MPIHelper& helper = Dune::MPIHelper::instance(argc, argv);
    std::cout << "Hola mundo, este es My-proyect01." << std::endl;
    if(Dune::MPIHelper::isFake)
      std::cout<< "Este es un programa secuencial" << std::endl;
    else
      std::cout<<"Soy un rango "<<helper.rank()<<" de "<<helper.size()
        <<"procesos!"<<std::endl;
    return 0;
  }
  catch (Dune::Exception &e){
    std::cerr << "Dune reported error: " << e << std::endl;
  }
  catch (...){
    std::cerr << "Unknown exception thrown!" << std::endl;
  }
}
