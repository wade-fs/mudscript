// Room: /u/b/bss/bug_room
#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "bug回報暨公佈room");
	set( "build", 38 );
  set ("long", "
本房間主要的用途是在給與玩家回報bugs和給巫師公佈已處理或未處理
的bug,本房間的使用原則如下:
" + HIY + "
(1)要回報bug的玩家,請用本房間所提供的(record)功\能,切勿將bug post
   在board上,否則巫師將以公佈bug的罪名與以嚴懲,輕者廢武功\,重者
   purge
(2)若發現在record中有不是回報bug的文章,也將以增加巫師工作負擔的罪
   名與以嚴懲,輕者ckill十次,重者purge
(3)在房間中的公佈欄主要是給巫師將已處理或未處理的bug公佈給玩家知
   道的,若有玩家亂post或是把它當成與巫師或玩家的聊天版,或者跟bug
   完全沒關係的文章,post的玩家也將與以嚴懲,輕者罰款,重者sleep
(4)回報的bug一經確定屬實之後,將會對該回報玩家與以獎勵,切勿獅子大開
   口,要些geq,meq這類的好防具,或者是大幅的提升自己能力的要求,雖然
   會以玩家所希望的為主,但是巫師還是會以玩家所回報的bug大小,決定
   到底要給啥好處
(5)本房間切忌使用於其他用途,例如發呆,練功\,逃避打鬥等,若經發現屬實
   一律ckill 10 次,沒得講
有別的以後再補.................
" + NOR);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/wiz/fsroom2",
]));
  set("objects",([
  "/obj/bug_record.c":1,
]));
  set("no_magic", 1);
  set("light_up", 1);
  set("no_fight", 1);
  setup();
}

