#include "/open/open.h"

inherit NPC;

void create()
{
  set_name("巧心姑娘", ({ "chou hsin", "hsin" }));
  set("race", "人類");
  set("gender", "女性");
  set("age", 18);
  set("long",@LONG
巧心姑娘從小精通音律, 其中尤以古箏名聞遐邇。據說每
當他彈奏家傳的古箏時, 鳥兒會忘了飛翔, 小魚會忘了游動,
農裡的伯叔會忘了除草。
LONG);
  set("attitude", "friendly");
  set("str", 17);
  set("cor", 23);
  set("combat_exp",1348);

  set_temp("apply/attack", 25);
  set_temp("apply/damage", 10);
  set_temp("apply/armor", 10);
  setup();
  carry_object(CENTER_OBJ"amulet1")->wear();
  carry_object(CENTER_OBJ"pant2")->wear();
  carry_object(CENTER_OBJ"cloth3")->wear();
  carry_object(CENTER_OBJ"goo_zheng")->wield();
}
