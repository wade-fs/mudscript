inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "奈何之路");
	set( "build", 1235 );
  set ("long","此路由七衣魔將分守, 絕對誓死保護焚天魔王的安全. 這裡的空間籠罩著
一股十分邪怪的瘴氣, 其間閃爍不定的光點映出了若有若無的景象, 千變
萬化擾人心神, 或是天災人禍, 或是燒殺擄掠, 盡是人間不幸悲劇, 加上
此處靜悄無響, 你的理性漸漸地隨著心跳與呼吸聲走火入魔了. 
");
set("evil", 1);
set("no_auc", 1);
set("no_transmit", 1);
set("light_up", -1);

set("exits", ([ /* sizeof() == 2  */
  
  "east" : __DIR__"room92",
  "south" : __DIR__"room87",
]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/seven-dark-1" : 1,
  __DIR__"npc/seven-dark-2" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)

{
        if(dir=="east"&&present("seven-dark",environment(me)))
  {

message_vision(HIY"七衣魔將說:「小子往哪走!!」\n"NOR,me);

return 0;
}
return 1;
}
