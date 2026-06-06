// jen.c
//排版與增加npc的eq by blazakira 2011/8/31

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("任青雲", ({ "fist_trainer jen", "jen", "trainer" }) );
  set("title"   , "拳法教練");
  set("nickname", "小李靖");
  set("gender"  , "男性" );
  set("class"   ,"fighter");
  set("age", 26);
  set("str", 26);
  set("int", 29);
  set("long",
    "任青雲是正晴武館的拳法教練, 亦是任家的二兒子, 儘管年紀輕但他的\n" +
    "拳法卻是此館數一數二的。由於他自小天資優於其他手足, 又酷愛讀書\n" +
    "使的他成為平南城著名的文武全才, 所以有『 小李靖 』之稱。\n" );
  set("attitude"      , "heroism");
  set("combat_exp"    ,300000);
  set("env/狂擊"      ,"YES");
  set("force"         , 2000);
  set("max_force"     , 1300);
  set("force_factor"  , 15);
  set("inquiry", ([
    "here": "這裡是任家正晴武館, 請問有何事指教?\n",
    "name": "在下姓任, 名青雲, 是本館的拳法教練\n",
    "lungshan": "這個啊..此為本館絕學, 在下對此頗有心得, 承蒙家父傳授。\n",
  ]) );
  set_skill("literate", 80);
  set_skill("lungshan", 80);
  set_skill("dodge"   , 50);
  set_skill("haoforce", 60);
  set_skill("force"   , 70);
  set_skill("unarmed" , 70);
  set_skill("parry"   , 70);
  set_skill("henma-steps",60);
  set_skill("fire-kee",50);
  map_skill("force", "haoforce");
  map_skill("unarmed", "lungshan");
  map_skill("dodge", "henma-steps");
  map_skill("parry", "fire-kee");
  set("chat_chance_combat",65);
  set("chat_msg_combat",({
    (: perform_action, "force.kang_kee"   :),
    (: "cmd god_kee"   :)
  }));
  setup();
  set("chat_chance"   , 25);
  set("chat_msg",
  ({
    // HIW + "論語曰: 大道之行 , 天下為公也.......\n" + NOR,
    HIW + "禮記禮運大同篇: 大道之行 , 天下為公也.......\n" + NOR,
    HIW + "任青雲喃喃說道: 書是吾人至寶, 怎能棄之！\n" + NOR,
    HIW + "任青雲大叫一聲: 啊! 父親給我的\"浩日心經\"呢？又不見了！我的記性真差！\n" + NOR,
  }));

  setup();
  carry_object(__DIR__"obj/fight_robe")->wear();
  carry_object("/open/wu/npc/obj/silverclaw.c")->wield();
  carry_object("/open/common/obj/flower_pants.c")->wear();
  add_money("gold", 10);
}

int recognize_apprentice(object ob)
{
  if( (string)ob->query("family/family_name")=="瀧山派" ) return 1;

  command("say 抱歉﹐這位" + RANK_D->query_respect(ob) + "﹐您不是我們武館的弟子。");
  return notify_fail( "任青雲不願意教你拳法。\n");
}

int accept_fight(object me)
{
  if( (string)me->query("family/family_name")=="瀧山派" ) {
    command("nod");
    command("say 出招吧!");
    return 1;
  }
  command("say 館主吩咐過﹐不許\和來這裡的客人過招。");
  return 0;
}
