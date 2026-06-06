#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIY"狂想空間歷史發展館"NOR);
        set( "long", "九八年七月,分站歷經了一件重大的事件!!!
1.老玩家milk(忘了還是acme)願意支持分站發展下去。
2.Acmesoft是華宇電腦的一個新事業部門,其負責人(acme)願意提供位置及主機。
  來support FS。
3.同時Wade回到分站來接手,並且利用第一次網聚時到Acmesoft公司洽淡GFS
  的事。
4.另外為了讓分站的FS更好,Wade將中興的狂想空間及分站(Nkit)一起搬到了交大
  ,因為這樣所以使分站可以拿到狂想空間的所有資料(之前欠缺的聖火及少林)
5.同時之間我進行了分站Fs的改板,將原有的Mudos v21c2提升到那時最新的v22 pre11
  的板本。
此重大事件在七、八、九、十月中陸續發生,同時lum、fir、wasami.等超強的高手
也在Wade的召集下來到FS分站來幫忙,Konn大大也是由Wade大大請回來管理那時中
興大學的狂想空間。
" );
  set("exits", ([
  "north" : __DIR__"newhand6-12",
  "south" : __DIR__"newhand6-14",
               ]));
  set("light_up", 1);
  setup();
}

