inherit ROOM;

void create ()
{
set ("short", "殺手休息室");
set ("long", @LONG
這裡是殺手們在接受一連串特訓之後，休息的好地方。有專人為你服務。
只不過，這可是中國四千年的秘密神功。可以快速回復體力。
但是，一般人如果體質不好，可是無法在短時間內，接受太多次回復。
想回復的就問氣功師，有關回復的事吧。。。。

LONG );

set("exits", ([ /* sizeof() == 2 */
     "east" : __DIR__"waterm.c",
]));

set("objects", ([ /* sizeof() == 1 */
"/open/killer/npc/rester.c" : 1,
]));

set("light_up", 1);
setup();
}
