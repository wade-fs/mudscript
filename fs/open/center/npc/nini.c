// nini.c

#include "/open/open.h"

inherit NPC;

void create()
{
  set_name("小女孩", ({ "Nini", "nini" }));
  set("race", "人類");
  set("gender", "女性");
  set("age", 10);
  set("long","從小女孩的衣著看來, 應該是富貴人家的孩子, 不知怎麼會出現在這個地方... 小女孩哭紅了眼, 滿頭散髮, 卻還倔強的瞪著你.\n");
  set("attitude", "peaceful");
  set("cor", 18);
  set("combat_exp",180);
  set("chat_chance", 4);

  set("chat_msg",({
    (: this_object() :),
    (: this_object() :),

    "小女孩恨恨的說道 : 你不要以為我好欺負 !\n",
    "小女孩咬牙切齒的說道 : 你要是敢欺負我, 我爸爸會找你算帳的 !\n",
    }));

  set_temp("apply/attack", 15);
  set_temp("apply/damage", 5);
  set_temp("apply/armor", 5);
  setup();
}
