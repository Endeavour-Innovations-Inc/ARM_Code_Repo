#define LED_DATA	(*((uint32_t *) 0x41210000))

#define XADC_BASE 0x43C50000
#define XADC_CTL (*((uint32_t *)(XADC_BASE+0x300)))

#define pot_register *((uint32_t *) 0x43C5020C)

#define VP 0x020C

//7-seg control register
#define SEG_CTL *((uint32_t *) 0x43c10000)

//7-seg digit data register
#define SEG_DATA *((uint32_t *) 0x43C10004)

//7-seg decimal point data reg
#define SEG_DP *((uint32_t *) 0x43C10014)

#define RGB_EN(n)	(*( (uint32_t *) (0x43C00000 +(16*n))))
#define RGB_PERIOD(n)	(*( (uint32_t *) (0x43C00004 +(16*n))))
#define RGB_WIDTH(n)	(*( (uint32_t *) (0x43C00008 +(16*n))))

#define PWM2_blueEn 0x43C00030

#define PWM2_greenEn 0x43C00040

#define PWM2_redEn 0x43C00050

#define CH_VCCINT	0
#define CH_TEMP		1
#define CH_VCCAUX	2
#define CH_VP		3
