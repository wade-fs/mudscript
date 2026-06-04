//      File    :  /include/ansi.h
//      Creator :  Gothic@TMI-2  
//
//      The standard set of ANSI codes for mudlib use.
 
#define ESC     ""
#define CSI     "\x1b["
 
                /*  Foreground Colors  */
 
#define BLK "\x1b[0;30m"        /* Black    */
#define RED "\x1b[0;31m"        /* Red      */
#define GRN "\x1b[0;32m"        /* Green    */
#define YEL "\x1b[0;33m"        /* Yellow   */
#define BLU "\x1b[0;34m"        /* Blue     */
#define MAG "\x1b[0;35m"        /* Magenta  */
#define CYN "\x1b[0;36m"        /* Cyan     */
#define WHT "\x1b[0;37m"        /* White    */
 
                /*   Hi Intensity Foreground Colors   */
 
#define HIK "\x1b[1;30m"        /* Black    */
#define HIR "\x1b[1;31m"        /* Red      */
#define HIG "\x1b[1;32m"        /* Green    */
#define HIY "\x1b[1;33m"        /* Yellow   */
#define HIB "\x1b[1;34m"        /* Blue     */
#define HIM "\x1b[1;35m"        /* Magenta  */
#define HIC "\x1b[1;36m"        /* Cyan     */
#define HIW "\x1b[1;37m"        /* White    */

                /* High Intensity Background Colors  */

#define HBRED "\x1b[41;1m"      /* Red      */
#define HBGRN "\x1b[42;1m"      /* Green    */
#define HBYEL "\x1b[43;1m"      /* Yellow   */
#define HBBLU "\x1b[44;1m"      /* Blue     */
#define HBMAG "\x1b[45;1m"      /* Magenta  */
#define HBCYN "\x1b[46;1m"      /* Cyan     */
#define HBWHT "\x1b[47;1m"      /* White    */
 
                /*  Background Colors  */
 
#define BBLK "\x1b[40m"         /* Black    */
#define BRED "\x1b[41m"         /* Red      */
#define BGRN "\x1b[42m"         /* Green    */
#define BYEL "\x1b[43m"         /* Yellow   */
#define BBLU "\x1b[44m"         /* Blue     */
#define BMAG "\x1b[45m"         /* Magenta  */
#define BCYN "\x1b[46m"         /* Cyan     */
#define BWHT "\x1b[47m"         /* White    */

// by babe
#define NOR "\x1b[0m"		/* Puts everything back to normal */
#define BOLD ESC+"[1m"          /* Turn on bold mode */
#define CLR ESC+"[2J"           /* Clear the screen  */
#define HOME ESC+"[H"           /* Send cursor to home position */
#define REF CLR+HOME            /* Clear screen and home cursor */
#define BIGTOP ESC+"#3"         /* Dbl height characters, top half */
#define BIGBOT ESC+"#4"         /* Dbl height characters, bottem half */
#define SAVEC ESC+"[s"          /* Save cursor position */
#define REST ESC+"[u"           /* Restore cursor to saved position */
#define REVINDEX ESC+"M"        /* Scroll screen in opposite direction */
#define SINGW ESC+"#5"          /* Normal, single-width characters */
#define DBL ESC+"#6"            /* Creates double-width characters */
#define FRTOP ESC+"[2;25r"      /* Freeze top line */
#define FRBOT ESC+"[1;24r"      /* Freeze bottom line */
#define UNFR ESC+"[r"           /* Unfreeze top and bottom lines */
#define BLINK ESC+"[5m"         /* Initialize blink mode */
#define U ESC+"[4m"             /* Initialize underscore mode */
#define REV ESC+"[7m"           /* Turns reverse video mode on */
#define HIREV ESC+"[1,7m"       /* Hi intensity reverse video  */
