#include <ansi.h>
inherit ROOM;

string do_shelf();
void create ()
{
  set ("short", "祕密書房");
	set( "build", 13 );
  set ("long", @LONG
走進這裡，你看到滿室的書櫃(shelf)及字畫(picture), 原來你已走進了
段雲的祕密書房, 段雲畢生蒐集的經典文集和武學寶典都收藏在此, 你心想如
果只拿走一兩本秘笈應該不會有人發現吧.....

LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "picture" : "天下風雲出我輩，一入江湖歲月摧，皇圖霸業談笑中，不勝人生一場醉。
",
  "shelf" : "這上面繙﹞F各種秘笈和文集, 你忍不住想拿幾本來翻(search)。",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/boy.c" : 1,
]));
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"p1",
  "pray" : "/open/ping/room/talkroom",
]));
  set("search_desc", ([ /* sizeof() == 1 */
  "shelf" : (: do_shelf :),
]));

  setup();
}

int valid_leave(object me, string dir)
{
if( dir=="pray" && me->query("family/family_name")!="段家" )
return notify_fail("洋蔥小丸子"NOR"似笑非笑的對你說: 不給進。\n");
        return ::valid_leave(me, dir);
}
string do_shelf()
{

        object me=this_player();
  if (me->query_temp("get_sbook") == 0)
{
          write("你仔細的觀看架上的書籍......\n\n突然有一本書從書架上掉了下來....\n");

          new("/open/ping/obj/sunforce_book")->move(__DIR__"np20");
          me->set_temp("get_sbook",1);

        }
        else
           return("你找了老半天，可是看不出有任何特殊之處。\n");
}

