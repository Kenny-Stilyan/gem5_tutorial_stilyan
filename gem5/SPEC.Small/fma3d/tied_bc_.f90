!!
!! 19. TIED BC
!!
      MODULE tied_bc_                                                   
                                                                        
      TYPE :: tied_bc_type                                              
        INTEGER          TBCID   ! Tied BC ID                              
        INTEGER          SetID   ! Node set ID (-n/0/n=-NPID/all/Set ID)   
        INTEGER          Code    ! Constraint code                         
        REAL(KIND(0D0))  Fmax    ! Maximum constraint force b/ breaking    
        REAL(KIND(0D0))  Ax      ! BC direction, x-component (Code=4,40,   
        REAL(KIND(0D0))  Ay      ! BC direction, y-component  44,8,80,88)  
        REAL(KIND(0D0))  Az      ! BC direction, z-component               
      END TYPE                                                          
                                                                        
      TYPE (tied_bc_type), DIMENSION(:), ALLOCATABLE :: TIED_BC         
                                                                        
      END MODULE tied_bc_
