#include <ansi.h>
inherit TRANS_ROOM;
void create()
{
    set("short","凌雲村驛站");
    set("long",@LONG
這裡是凌雲村的驛站, 因為這裡是以產稻米為主, 所以你經常可以
看到許多農夫以牛車載著一袋袋的稻米來這, 請驛站老闆幫他們把稻米
運往各處.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/start/room/s4",
]));

    setup();
}
