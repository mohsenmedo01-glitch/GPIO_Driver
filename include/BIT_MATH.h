                                    /*     author : Mohamed Junior          */
                                /*          Date 20/10/2026            */
#ifndef BIT_MATH_h
#define BIT_MATH_h
#define SET_BIT(REG,BIT_NUM)                          REG |=(1<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM)                          REG &=~(1<<BIT_NUM)
#define TOG_BIT(REG,BIT_NUM)                          REG ^|=(1<<BUT_NUM)
#define GET_BIT(REG, BIT_NUMBER)                      ((REG & (1 << BIT_NUMBER)) >> BIT_NUMBER) 
#define CLR_2BITS(REG, POS, MASK)                     ((REG) &= ~((MASK) << (POS)))
#define SET_2BITS_VALUE(REG, POS, VALUE)              ((REG) |= ((VALUE) << (POS)))


#endif 

