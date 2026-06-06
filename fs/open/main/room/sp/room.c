inherit ROOM;
#include <ansi.h>
#include <room.h>

string show();

void create ()
{
        set("short",YEL"元神精煉房"NOR);
	set( "build", 24 );
        set("long", @LONG
一踏入門檻，敲打重物的聲音不絕於耳，青銅製的鍋爐，裡面並
沒有燃燒任何東西，卻傳來一陣一陣的熱氣，眼前也沒有任何人在敲
擊物品，卻有一陣一陣的敲打聲，房屋的正中央版放了一張樟木製的
桌子，桌子四邊各擺設著板凳。

木桌上擺了一張紙(paper)。
LONG);
        set("exits", ([ 
"out":"/open/main/room/r26",
"north":"/open/area/house/h02",
]));
        set("item_desc",([
"紙":(:show():),
"paper":(:show():),
]));
        set("objects",([
__DIR__"maker":1,
__DIR__"man01":1,
//__DIR__"stone":1, 女媧石先取消
]));
        create_door("north","木門","south",DOOR_CLOSED);
setup();
}

string show()
{
object me = this_player();
int a,b,c,d,e,f;
        a = me->query("refine/common/soul");
        b = me->query("refine/common/level");
        c = me->query("refine/common/force");
        d = me->query("refine/common/dodge");
        e = me->query("refine/common/move");
        f = me->query("refine/common/parry");

        tell_object(me,HIY"
  元 神 "+a+" 個        精煉等級 "+b+" 級       精煉內力 "+c+" 級

 精煉輕功\ "+d+" 級      精煉行動 "+e+" 級       精煉招架 "+f+" 級

\n"NOR,me);
return "紙上面模糊的記載著這些..\n\n";
}

