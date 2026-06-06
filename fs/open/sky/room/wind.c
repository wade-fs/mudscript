//敘述設計by test軍團長, code by blazakira 2011/8/20

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", GRN + "風靈天界" + NOR);
  set ("long", @LONG
狂風陣陣，雷電交加，阻礙了你眼前的視線，更讓你猶豫是否該
繼續前進，不過既然已走到這地方，怎麼可以放棄而往回走，冒險正
是讓自己更加茁壯的泉源，於是小心翼翼往前行走，前方有塊巨石，
仔細一看巨石上有八個孔洞，似乎等待著有緣人將其解放。

LONG);

  set("no_auc", 1);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("exits", ([ /* sizeof() == 1 */
    "west"  : __DIR__"road05",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/sky/stone/windfon" : 1,
  ]));
  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 1 */
    "designer" : "敘述設計by test軍團長, code by blazakira 2011/8/20",
  ]));
  setup();
}
