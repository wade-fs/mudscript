//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/1/7

#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 
inherit NPC;
inherit SSERVER;

void create()
{
  set_name("木無言",({"Silent Tree","tree"}));
  set("long","
英雄真經傳人，自幼修習三百年前的正道第一武學『" + HIW + "英雄真經" + NOR + "』
經內記載當代五大玄門正派的頂級武功\，包括：
" + HIW + "無雙寺：" + HIM + "無雙拳
" + HIW + "閃電山莊：" + HIY + "閃電步
" + HIW + "天劍宗：" + CYN + "馭天劍-" + HIC + "本來無一劍
" + HIW + "柳葉山莊：" + GRN + "超絕霸刀-" + HIG + "柳葉霸刀
" + HIW + "少林寺：" + RED + "菩提拂拭神功\-" + HIR + "本來無一物
\n" + NOR);
  set("attitude", "heroism");
  set("gender","男性");
  set("no_get",1);
  set("combat_exp",9999999);
  set("score",9000000);
  set("sec_kee","god");
  set("max_s_kee",1000);
  set("s_kee",5000);
  set("age",24);
  set("class","blademan");
  set("family/family_name","我流");
  set("title",HIC + "『英雄真經』" + HIW + "傳人" + NOR);
  set("max_gin",90000);
  set("max_kee",150000);
  set("max_sen",90000);
  set("bellicosity",99999);
  set("max_force",90000);
  set("force",999999);
  set("max_atman",50000);
  set("max_mana",50000);
  set("atman",60000);
  set("mana",60000);
  set("force_factor",50);
  set("str",45);
  set("cor",45);
  set("cps",50);
  set("int",30);
  set("con",35);
  set("per",30);
  set("spi",30);
  set("kar",30);
  set_skill("hero",160);
  set_skill("winter-steps",160);
  set_skill("superforce",250);
  set_skill("unarmed",140);
  set_skill("literate",120);
  set_skill("dodge",120);
  set_skill("parry",120);
  set_skill("force",400);
  map_skill("unarmed","hero");
  map_skill("parry","hero");
  map_skill("force", "superforce");
  map_skill("dodge", "winter-steps");
  setup();
  carry_object("/open/magic-manor/obj/hwa-je-icer.c")->wield();
  call_out("leave",3,this_object());
}

int leave(object me)
{
  if(environment() && all_inventory(environment()))
  {
    foreach(object obj in all_inventory(environment()))
    {
      if(obj == me) continue;
      if(!userp(obj)) continue;
      obj->set("startroom","/open/wiz/courthouse");
      if(obj->query("combat_exp") < 3000000) {
        tell_object(obj,HIR+"\n\n你這種無名小輩不要在此丟臉了！！\n\n"+NOR+HIC+"一陣光線籠照下來，突然間你沒有任何知覺，醒來後已經在客棧了。\n\n\n"+NOR);
        obj->move("/open/trans/room/room4");
      }
    }
  }
}

void init()
{
  add_action("do_use","use");
  ::init();
}

int do_use(string arg)
{
  object ppl = this_player();
  if(arg == "lotch")
  {
    message_vision(HIR + "\n$N：「......」(什麼軒轅劍俠刀神的，在我手下全都不堪一擊。)\n" + NOR,this_object());
    ppl->unconcious();
    return 1;
  }
}

void heart_beat()
{
  object me,*target,room;
  int exp1,exp2,i,j,kee,mkee,sen,msen,gin,mgin,ekee,egin,esen;
  me = this_object();
  room = environment(me);
  if(!me || !room) return ;

  kee=me->query("kee");
  mkee=me->query("max_kee");
  sen=me->query("max_sen");
  msen=me->query("max_sen");
  gin=me->query("max_gin");
  mgin=me->query("max_gin");
  target=me->query_enemy(room);
  i=sizeof(target);

  for(j=0;j<i;j++)
  {
    exp1=me->query("combat_exp");
    if(!target[j]) continue;
    exp2=target[j]->query("combat_exp");
    if(present( "xstrike-hands",target[j])) {
      exp2=exp2+exp2/2;
      if(exp2>exp1)
        me->set("combat_exp",exp2+random(16888));
    }
    else {
      if(exp2>exp1)
        me->set("combat_exp",exp2+random(16888));
    }
  }

  if(random(100) < 28 && !me->query_temp("unconcious")) //回精氣神
  {
    if(kee < mkee || sen < msen || gin < mgin)
    {
      message_vision(HIB + "$N運起少林寺最高內功\心法" + HIW + "『" + BRED+HIY + "本來無一物" + NOR + "" + HIW + "』" + HIB + "
內勁變得如黑洞般深不可測，原本散發的凜冽鬥氣剎那間完全消失，
$N竟與自然化為一體，全身傷勢疾速復原。\n" + NOR,me);

      ekee=me->query("eff_kee");
      egin=me->query("eff_gin");
      esen=me->query("eff_sen");
      me->receive_curing("kee",500+(mkee-kee)/7);
      me->receive_heal("kee",500+(mkee-ekee)/7);
      me->receive_curing("gin",300+(mgin-gin)/5);
      me->receive_heal("gin",300+(mgin-egin)/5);
      me->receive_curing("sen",300+(msen-sen)/5);
      me->receive_heal("sen",300+(msen-esen)/5);
      COMBAT_D->report_status(me);
    }
  }
  if(me->is_busy() && random(100)< 40 && !me->query_temp("unconcious"))
  {
message_vision(HIR + "$N潛運" + HIW + "ξ" + BRED+HIY + "本來無一物" + NOR + "" + HIW + "ξ" + HIR + "神功\，身形浮起，爆發無匹內勁掙脫束縛，
接著以閃電山莊的" + HIW + "ξ" + BRED+HIY + "閃電身法" + NOR + "" + HIW + "ξ" + HIR + "迅速脫離封鎖。\n" + NOR,me);
    me->delete_busy();
    if(me->is_fighting())
    {
      message_vision(HIG + "並且在電光石火間向每個人出招反擊!!\n" + NOR,me);
      for(j=0;j<i;j++)
      {
        if(target[j] && target[j]->is_character() && !target[j]->is_corpse() && room == environment(target[j])) 
          COMBAT_D->do_attack(me, target[j], me->query_temp("weapon"), TYPE_QUICK);
      }
    }
  }
  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
//  object *enemy;
  int i,j;
  object ob,winner = query_temp("last_damage_from");
  object me,sick,spirit;
  string name = winner->query("name");
  me=this_object();
/*
  enemy=me->query_enemy();
  i=sizeof(enemy);
*/
  if( winner->query("clan/id") && userp(winner) )
    CLAN_D->add_clanset( winner->query("clan/id"), "develop" ,  1 );
  tell_object(users(),HIG + "\n就在木無言將被"+winner->query("name")+"擊斃的同時，烏雲密佈的京城上空降下一道曙光，
一位和尚撐著雨傘，緩緩御風而降...


黃帝病" + HIM + "朗聲說道" + HIW + "：
                貧僧身負" + HIW + "ζ" + HIY+BRED + "魔界金典" + NOR + "" + HIW + "ζ，和修習∮" + HIC+BBLU + "英雄真經" + NOR + "" + HIW + "∮的木無言
                乃命中宿敵，在貧僧轟下木無言之前，任何人都沒資格敗他
                想殺他的人，就只有死!!

                " + HIR + ""+winner->query("name")+"" + HIW + "!!  來領死吧!!\n\n" + NOR);

  if(winner && !winner->query_temp("not_robot") && random(400)==0) {
    ob=new("/open/doctor/doctor_book/obj/scrap");
    ob->set("sort","井");
    ob->move(winner);
    message_vision(MAG + "\n從木無言的身上掉下了一塊靈魂碎片!!\n" + NOR,winner);
  }
  else if(winner && winner->query_temp("not_robot") && random(400)<133) {
    ob=new("/open/doctor/doctor_book/obj/scrap");
    ob->set("sort","井");
    ob->move(winner);
    message_vision(MAG + "\n從木無言的身上掉下了一塊靈魂碎片!!\n" + NOR,winner);
  }

  message_vision(HIY + "\n"+winner->name()+"打敗木無言得到一百二十點戰功\!!\n" + NOR,winner);
  write_file("/log/get_warp",sprintf("%s(%s) 打敗木無言得到一百二十點戰功\於 %s\n",
    winner->name(1),winner->query("id"),ctime(time())));
  winner->add("war_score",120);
  winner->set_temp("kill_hero",1);
  sick = new("/open/capital/npc/sick");
  sick->move(environment(me));
  if( random(5) == 2 && userp(winner) )
  {
    spirit = new("/open/ghost-hole/obj/light-spirit");
    spirit->move(winner);
    log_file("/sky/spirit/light-spirit",sprintf("%s(%s)讓木無言掉下了%s於 %s\n",winner->name(1),winner->query("id"),spirit->query("name"),ctime(time())));
    message_vision(HIY + "薀含在"+me->query("name")+HIY + "身體中的"+spirit->query("name")+HIY + "飛射而出，落在$N" + HIY + "手中。\n" + NOR,winner);
  }
  sick->kill_ob(winner);
  winner->start_busy(1);
  destruct(present("tree"));
}
