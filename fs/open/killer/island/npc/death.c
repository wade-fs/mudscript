#include <ansi.h>
inherit NPC;
void create ()
{
  set_name("死神",({"death"}));
  set("long","    一塊黑布包住了整個身體，約略可以看到藏在頭罩下的頭顱
，手持鐮刀，不斷的揮舞，空洞的眼眶還不時的露出青光。\n");
  setup();
  carry_object("/open/killer/island/obj/head");
}
