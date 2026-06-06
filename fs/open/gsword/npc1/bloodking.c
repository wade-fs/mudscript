//加入劍魔轉回仙劍的解謎要素 by Alucard 2009/08
//排版與補上title的結尾參數NOR 與暫時使用死亡訊息的參數 by blazakira 2011/10/17

inherit NPC;
#include <ansi.h>
#include "/open/open.h"

string  ask_title();

void create()
{
  set_name(HBRED"血魔"NOR,({"bloodking","king"}));
  set("long","天魔轉世..不過在先前與由仙劍派祖師逍遙子所率領的武林同盟大戰
失利後..就消失武林,如今已捲土重來.由其眼中..可明顯的看出其對
仙劍派的恨意似乎無窮無盡..\n");
  set("gender","男性");
  set("class","swordsman");
  set("family/family_name","仙劍派");
  set("combat_exp",20000000);
  set("attitude","heroism");
  set("dragon-sword",1);
  set("bellicosity", 100000);
  set("age",200);
  set("title",HIR"萬魔至尊"NOR);
  set("str", 70);
  set("cor", 50);
  set("cps", 70);
  set("con", 60);
  set("int", 30);
  set("max_gin", 50000);
//  set("gin",60000);
  set("max_kee", 100000);
//  set("kee",100000);
  set("s_kee",10000);
  set("max_s_kee",10000);
  set("force",200000);
  set("max_force",100000);
  set_skill("literate",80);
  set_skill("magic",100);
  set_skill("spells",50);
  set_skill("blood_sword",200);
  set_skill("fireforce",300);
  set_skill("move",120);
  set_skill("force",300);
  set_skill("dodge",220);
  set_skill("parry",220);
  set_skill("ghost-steps",220);
  set_skill("sword",170);
  set_skill("celestrike",500);
  set_skill("unarmed",500);
  set("swordskill/sword1",1);
  set("swordskill/sword2",1);
  set("swordskill/sword3",1);
  set("swordskill/sword4",1);
  set("swordskill/sword5",1);
  set("swordskill/sword6",1);
  set("swordskill/sword7",1);
  set("swordskill/sword8",1);
  map_skill("dodge","ghost-steps");
  map_skill("unarmed","celestrike");
  map_skill("move","ghost-steps");
  map_skill("force","fireforce");
  map_skill("sword","blood_sword");
  map_skill("parry","blood_sword");
  set("force_factor",50);
  set("inquiry",([
    "血魔" : "就是我ㄚ..",
    "逍遙子" : "可惡得逍遙子…當初就是他..害我慘遭封印",
    "劍法" : "就是我所創的劍招..你在這拿我的筆記(take bloodbook)去讀吧.",
    "血魔殺法" : "血魔殺法是血魔霸劍式中最厲害的殺招，此招有三大類，水之技、炎之技、嵐之技，各有各之優缺點，若你能幫我殺掉風青雲、鳳祥天以及逍遙子，我就各傳你一招血魔殺法精要。",
    "title":(:ask_title:),
  ]));
  set("ann_die",1);
  setup();
  carry_object("/open/gsword/obj1/sadsword")->wield();
  carry_object("/open/gsword/obj1/bloodring.c")->wear();
  add_money("gold",5);
}

void init()
{
  object obj;
  add_action("do_cover","cover");
  ::init();
  if(interactive(obj=this_player()) && !is_fighting())
  {
    remove_call_out("greeting");
    call_out("greeting",1,obj);
  }
}

void greeting(object ob)
{
  command("wear all");
}

string ask_title()
{
  object me = this_player();
  if(me->query("family/family_name") != "血魔一派")
  {
    return "你是哪裡來的人！敢在此吵吵鬧鬧的，要求東要求西的，回去家鄉吃奶吧！";
  }
  me->set("title",HIW"Π"HIR"魔"HIC"亟"HIY"劍宗"HIW"Π"NOR);
  return "我賜你這個名字，你不要忘記我們本來的初衷啊，對於某人，千萬不可以手下留情。";
}

int do_cover(string arg)
{
  object me,lwater,king,mob;
  me = this_player();
  king = this_object();
  lwater = present("living-water",me);
  if(!arg || (arg!="bloodking" && arg!="king")) return 1;
  if(!lwater) return 1;
  if(!me->query_temp("quest/return_sha") || me->query_temp("quest/return_sha") != 7) return 1;
  destruct(present("living-water",me));
  message_vision(HIG"$N突然將生命之水灑在血魔身上，陣陣血氣自$N身上蒸發，血魔印記已消失殆盡了。\n"NOR,me);
  me->delete("swordskill/bloodz");
  me->delete("swordskill/sword1");
  me->delete("swordskill/sword2");
  me->delete("swordskill/sword3");
  me->delete("swordskill/sword4");
  me->delete("swordskill/sword5");
  me->delete("swordskill/sword6");
  me->delete("swordskill/sword7");
  me->delete("swordskill/sword7a");
  me->delete("swordskill/sword8");
  me->delete("swordskill/fsword8");
  me->delete("swordskill/fsword7");
  me->delete("swordskill/fsword6");
  me->delete("swordskill/fsword5");
  me->delete("swordskill/fsword4");
  me->delete("swordskill/fsword3");
  me->delete("swordskill/fsword2");
  me->delete("swordskill/fsword1");
  me->delete("quests/findtesin");
  me->delete("bloodsword");
  me->delete("highsworder");
  me->delete("swordquest/findball");
  me->delete("return");
  me->delete_temp("swordquest/findball");
  me->delete_temp("swordquest/fball");
  me->delete_temp("swordquest/ball");
  me->delete_temp("qsword");

  me->set_temp("quest/return_sha",8);
  command("angry");
  command("say 叛徒!!死吧!!");
  kill_ob(me);
  message_vision(HIM"$N大為受驚，連忙躲回密道內，並立刻封住出口。\n"NOR,me);
//  me->move(__DIR__"room/tunnel_10");
  me->move("/open/gsword/return_sha/room/tunnel_10");
  message_vision(HIM"但為時已晚，護衛的血魔將強行突破洞口進來追殺$N!!\n"NOR,me);
  mob = new("/open/gsword/npc2/bknightw");
  mob->set_temp("quest/return_sha",9);
  mob->move(environment(me));
  mob->set_leader(me);
  mob->kill_ob(me);
  return 1;
}
