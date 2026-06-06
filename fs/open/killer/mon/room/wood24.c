//written by acelan...../u/a/acelan/room/wood24.c

inherit ROOM;

void create()
{
        set("short", "神祕的地道");
        set("long", @LONG
地道繼續的前進, 前方偶有落下的樹根擋住你的去路, 並且阻礙
了你的視線, 上方不時會滴下幾滴水滴, 使整個地道滴答滴答地作響
, 一陣寒意突然由你的背脊往上竄升......
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "east" : "/open/killer/mon/room/wood25.c",
       "west" : "/open/killer/mon/room/wood23.c",
   ]));
        set("no_clean_up", 0);

        setup();
        }
