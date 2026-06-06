// by frequency 2003 /8/14
//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/1/21
//將add("kee")調整為receive_damage的攻擊參數並補上攻擊方之參數 by blazakira 2011/4/23

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
  set_name("海皇", ({ "dragon-god","dragon","god" }) );
  set("long","傳說中的海龍王。\n");
  set("title",HIY + "龍神" + NOR);
  set("age", 10000);
  set("class","blademan");
  set("attitude", "friendly");
  set("family/family_name","北極圈");
  set("max_gin", 1400000);
  set("max_kee", 1400000); //給如此高的值是因為這個npc不需殺死
  set("max_sen", 1400000);
  set("max_force", 2000000);
  set("force", 9000000);
  set("force_factor",55);
  set("str", 90);
  set("cor", 90);
  set("spi", 90);
  set("int", 90);
  set("cps", 90);
  set("con", 90);
  set("kar", 90);
  set("per", 90);
  set("combat_exp", 30000000);
  set("god",1);
  set("use_light_ring",-999);
  set("bellicosity",100000);   
  set_skill("dodge",120);
  set_skill("parry",120);
  set_skill("lance",120);
  set_skill("force",450);
  set_skill("water-lance",100);
  set_skill("iceforce",100);
  set_skill("snow-kee",100);
  set_skill("winter-steps",100);
  map_skill("lance","water-lance");
  map_skill("parry","snow-kee");
  map_skill("dodge","winter-steps");
  map_skill("force","iceforce");

  set_temp("apply/attack", 100);
  set_temp("apply/damage", 100);
  set_temp("apply/armor",  100);
  set_temp("apply/defense",200);
  set_temp("apply/dodge", 100);
  set_temp("apply/parry", 100);
  set_temp("def_cold",1);
  set("no_plan_follow",1);
  set_temp("mount",1);
  set_temp("follow",1);
  set_temp("rob",90);  
  set_temp("no-plan",1);
  set_temp("no_die_soon",1);
  setup();
  carry_object("/open/north-polar/obj/lance")->wield();
  carry_object("/autoload/north-polar/light-ring")->wear();
}

void init()
{
  add_action("do_use","use");
  add_action("do_catch","catch");
  ::init();
}

void greeting()
{
  command("wield sky-water-lance");
  command("wear light-ring");
  this_object()->apply_condition("powerup",9999);
}

void heart_beat()
{
  object env,mob,*enemy,obj;
  int i,j,damage;

  mob = this_object();
  env = environment(mob);

  if( mob->query("kee")<700000 && random(200)<50 && !mob->is_busy() )
  {
    message_vision(HIW + "\n海皇運起神族祕極之" + HIM + "修羅" + HIC + "永" + HIG + "生" + HIY + "訣" + HIW + "，身上傷勢立刻復原不少。\n" + NOR,mob);
    mob->receive_curing("kee",1000);
    mob->receive_heal("kee",1000); 
  }

  if(mob->is_fighting() && random(1000) < 450)
  {
    enemy = all_inventory(environment(mob));
    i=sizeof(enemy);
    message_vision(BCYN + "
" + NOR + " ▂▁▁ˍ▁ˍ▁ˍ" + WHT + "ˍˍ                                          
" + NOR + "" + BYEL + "   " + WHT+BYEL + "▂▅▆▇" + BLU+BWHT + "▃▅▆▇" + HIC+BBLU + "                                                               
" + NOR + "" + BYEL + "  " + BWHT + "▇▅▃" + WHT+BBLU + "▆▅▂                                                                    
" + NOR + "" + BYEL + "          " + YEL+BWHT + "▆▃▂▁" + WHT+BBLU + "▇▄▂▁                                                        
" + NOR + "" + BYEL + "                    " + YEL+BWHT + "▇▆▅▂" + WHT+BBLU + "▅                                                    
" + NOR + "" + BYEL+HIC + "                 " + WHT+BYEL + "▂▃▄▅▆" + BLU+BWHT + "▃" + HIC+BBLU + "                                                     
" + NOR + "" + BYEL+HIC + "                " + YEL+BWHT + "▇▆▄▃▁" + WHT+BBLU + "▆▃▁                                                  
" + NOR + "" + BYEL + "                            " + YEL+BWHT + "▅▄▂" + WHT+BBLU + "▅▄▃▂▁                                      
" + NOR + "" + BYEL + "                                    " + YEL+BWHT + "▇▆▄▃▁" + WHT+BBLU + "▅                                  
" + NOR + "" + BYEL + "                                       ▂▅▆▇" + BLU+BWHT + "▄" + HIC+BBLU + "                                 
" + NOR + "" + BYEL+HIC + "                                        " + YEL+BWHT + "▆▅▄▃" + WHT+BBLU + "▆                                
" + NOR,mob);
    message_vision(HIB + "海皇引發巨大的驚人海嘯，將在場一切完全淹沒。\n" + NOR,mob);
    for (j=0 ; j < i ; j++)
    {
      if(enemy[j] && enemy[j]->is_character() && !enemy[j]->is_corpse() && enemy[j]!=mob && 
        !wizardp(enemy[j]) && env == environment(enemy[j])) 
      {
        tell_object (enemy[j],HIW + "滔天巨浪對你造成毀滅性的衝擊!!\n" + NOR);
        if(enemy[j]->query("def_cold")) damage = 900 + random(1000);
        else damage = 1800 + random(2000);
        enemy[j]->receive_wound("kee",damage,mob);
        enemy[j]->apply_condition("cold",12);
        enemy[j]->apply_condition("ice", 12);
        COMBAT_D->report_status(enemy[j]);
      }

//加入銀針門神農quest所需 temp by blazakira 因為是在心跳裡判斷 所以頻率相當高 因此降低機率 >> 450/1000 * 15%=6.75%
      if (enemy[j] && enemy[j]->query("family/family_name")=="銀針門" && random(100) > 85 && query_temp("record_damage/"+enemy[j]->query("id")) > query("max_kee")/5) {
        enemy[j]->set_temp("spiritup","dragon-god");
      }

    }
  }  
/* 因為已調整為非天道吃白龍pill效果變差，故先解除這個心跳 by Alucard/2009/Sep
  for(j=0;j<i;j++) 
  {
    if(!living(enemy[j])) continue;
    if(!enemy[j]->query_temp("hardshell") || enemy[j]->query("class")=="taoist") continue;
    enemy[j]->delete_temp("hardshell");
    enemy[j]->clear_condition("white_pill");
    message_vision(HIY + "\n海皇的龍睛爆出陣陣耀眼虹光，$N身上的硬甲護持消失了。\n" + NOR,enemy[j]);
  }*/

  set_heart_beat(1);
  ::heart_beat();
}

int do_use(string str)
{
  object me,mob;
  me = this_player();
  mob = present("shan yun");
  if(present("lotch",me) && str == "lotch")
  {
    if(mob)
    {
      message_vision(HIY + "\n$n臣服於海皇的神聖氣息，竟爾倒戈向$N出手。\n" + NOR,me,mob);
      mob->set_leader(me);
      mob->kill_ob(me);
    }
  }
}

int do_catch(string str)
{
  object me,lotch;
  me = this_player();
  lotch = present("lotch",me);
  if(present("lotch",me) && (str == "dragon-god" || str == "dragon" || str == "god"))
  {
    message_vision(HIY + "\n海皇冷冷的向$N一瞥，一道精光射向手中，" + HIB + "煉妖壺" + HIY + "應聲而碎。\n" + NOR,me);
    destruct(lotch);
  }
  return 1;
}

void unconcious()
{
   this_object()->revive();
   message_vision(HIW + "\n海皇頻死之際，赫然運起" + HIY + "皇" + HIB + "極" + HIM + "不" + HIG + "滅" + HIC + "身" + HIW + "，身上傷勢立即痊癒大半。\n" + NOR,this_object());
   this_object()->set("kee",500000);
   this_object()->set("gin",500000);
   this_object()->set("sen",500000);
   this_object()->set("eff_kee",1400000);
   this_object()->set("eff_gin",1400000);
   this_object()->set("eff_sen",1400000);
}

void die()
{
  object winner,mob,room;
  winner = query_temp("last_damage_from");
  mob = this_object();
  room = environment(mob);
  tell_object(users(),HIW + "\n大水退去，冰山再度凝結，" + HIG + ""+winner->query("name")+"" + HIW + "以不屈不撓挑戰神的勇氣終於擊潰了" + HIR + "龍神" + HIW + "。
 
 
    " + HIY + "海皇" + HIW + "與他的霸念，終於自歷史上消失無蹤了... \n\n" + NOR);

  if(userp(winner)) {
    if(winner->query("combat_exp") < 30000000)
    {
      message_vision(HIG + "\n$N殺敗$n得到33333點經驗值\n" + NOR,winner,mob);
    }
    if(!present("light-ring",winner))
    {
      new("/autoload/north-polar/light-ring")->move(winner);
      message_vision(HIG + "\n$N從$n身上取下一枚戒指。\n" + NOR,winner,mob);
      write_file("/log/north-polar/get_ring",sprintf("%s(%s) 擊敗海皇得到淨水光之戒於 %s\n",winner->name(1),winner->query("id"),ctime(time())));
    }else{winner->set("use_light_ring",0);}
  }
  destruct(present("stela"));
  room->delete_temp("god-die");
  room->delete_temp("punch-1");
  room->delete_temp("punch-2");
  room->delete_temp("punch-3");
  room->delete_temp("punch-4");
  room->delete_temp("punch-5");
  room->delete_temp("punch-6");
  room->delete_temp("punch-7");
  room->add("exits/up","/open/north-polar/old-temple");
  call_out("close",40,room);
  ::die();
}

int close(object room)
{
  message_vision(YEL + "\n強光逐漸淡去，通路也隨著消失。\n" + NOR,room);	
  room->delete("exits/up");
  return 1;
}

void record_damage(int damage, object who)
{
  if(!who) return ;
  if(who && !userp(who)) return ;
  add_temp("record_damage/"+who->query("id") , damage);
}
varargs int receive_damage(string type, int damage, object who)
{
  ::receive_damage(type,damage,who);
  who = query_temp("last_damage_from");
  record_damage(damage,who);
}
varargs int receive_wound(string type, int damage, object who)
{
  ::receive_wound(type,damage,who);
  who = query_temp("last_damage_from");
  record_damage(damage,who);
}
