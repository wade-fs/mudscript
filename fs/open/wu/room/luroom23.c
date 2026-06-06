// Room: /open/wu/room/luroom23.c
// 瀧山武館的禁地
inherit ROOM;
void create ()
{
  set ("short", "禁地");
  set ("long", @LONG
這裡是瀧山武館內的禁地門口,往下話是通往瀧山派所嚴令禁止的禁地
禁地的看守者是瀧山派第六代弟子中絕頂的弟子---任嚴天、李定延---
從他們身上所散發的氣味就可以知道他們絕對是一流的高手,有他們來看
守瀧山的禁地,絕對是萬無一失。北邊則是通往瀧山武館的內院。
LONG);
  set("exits", ([ /* sizeof() == 5 */
  "north" : "/open/wu/room/luroom20",
  "down" : "/open/wu/room/gen1",
  ]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
        "/open/wu/npc/sky_yan_jen" : 1,
      "/open/wu/npc/yan_din_lee" : 1,
]));
  setup();
}
int valid_leave(object me, string dir)
{
 if( dir == "down")
{
if((me->query("family/family_name") == "瀧山派")
	&& me->query("final/ko_king"))
	return 1;
if(me->query("title")=="瀧山奧義傳人")
return 1;
if((me->query("family/family_name") == "瀧山派") && (me->query("title") != "瀧山絕學傳人"))
      return notify_fail("只有瀧山絕學傳人才能進禁地!!\n");
else
if(!me->query("go_ya"))
      return notify_fail("只有對瀧山派有恩的人才能通行無阻!!\n");
return ::valid_leave(me,dir);
}
   return ::valid_leave(me,dir);
}
