inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "涼亭");
        set("long", @LONG
此亭架設在長方形的水池上，重簷構頂，上覆紅瓦，亭頂處再扣
一個造型華美的寶頂，下面則是白石臺階，欄杆雕紋精美，只見這座
亭，便可以感受到造者的品味與匠心。
LONG
);
set("exits", ([ /* sizeof() == 2 */ 
"north" : "/open/tendo/room/tower/water2.c", 
"west" : "/open/tendo/room/tower/tomb.c",
]));
set("objects", ([ /* sizeof() == 2 */
"/open/tendo/room/tower/npc/genies.c" : 2,
]));
      set("outdoors",1);
	setup();

}


