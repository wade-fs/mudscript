// Room: /u/d/dhk/questsfan/rm1
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", ""HIY"嵩山"CYN"地界"NOR"");
  set ("long", "此地就是名聞暇爾的五嶽之首〝中嶽嵩山〞地界。傳聞\n"
+"中嶽嵩山因地形地勢特殊的關係，向來有不少隱士、武林高\n"
+"手將此地當成隱居避世之地。而且來來往往的遊客、行人有\n"
+"不少誤中他們設的機關、迷陣因而喪命。久而久之，嵩山本\n"
+"身已是靈氣黯然又加入離奇的路徑、迷陣，為中嶽更增加許\\n"
+"多不少神秘的色彩。若無熟人帶路就莽然入山，簡直找死的\n"
+"的行為。\n"
+"                                          ┌──┐\n"
+"                                        ┌┘    │\n"
+"                                        |   "HIY"嵩"NOR"   |\n"
+"                                        |   "HIY"山"NOR"   |\n"
+"                                        |   "HIY"地"NOR"   |\n"
+"                                      __|__ "HIY"界"NOR" __|__\n"
+"\n"
);

  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"rm2",
"westdown" : "/open/main/room/M16",
]));

  setup();
}
