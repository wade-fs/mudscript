//by casey
//將add("kee")調整為receive_damage的攻擊參數並補上攻擊方之參數 與強化取得item列表的判斷以減少錯誤產生 by blazakira 2011/6/2

#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N" + HIK + "兇性大發 ,銳利的指甲向$n狠狠的抓了過去 ,似要撕裂$n" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "抓傷",
           ]),
([ "action" :"$N" + HIK + "迅速撲至$n面前 ,滿天揮舞著雙掌朝$n猛擊下去 ,$n當場鮮血飛濺" + NOR + "。
",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "抓傷",
            ]),
([ "action" :"$N" + HIK + "將全身力量集中在手上 ,狠狠的往$n脖子夾住 ,好不驚人" + NOR + "。
",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  240,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N" + HIK + "朝$n猛撞了過去 ,千斤重的身體 ,挾著萬均之勢 ,令人髮指" + NOR + "。
",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  275,
             "damage_type":  "撞傷",
            ]),
([ "action":"$N" + HIK + "一聲狂吼 ,從口中噴出" + HIR + " 毒氣 " + HIK + "將$n的身體整個攏罩住" + NOR + "。",
             "dodge"      : -30,
             "parry"      :  -30,
             "damage"     : 292,
             "damage_type":  "嚴重灼傷",
           ]),
       });

void create()
{
  set_name(HIK + "殭屍" + NOR ,({"zombie"}) );
  set("long","生前身上帶著許\多金銀財寶下葬，但因為埋的地點不對，而變成殭屍。\n");
  set("race", "人類");
  set("clan_kill",1);
  set("title", "殭屍洞");
  set("age",103972);
  set_temp("apply/attack",470);
  set_temp("apply/damage",470);
  set_temp("apply/move",470);
  set("bellicosity",40000);
  set("max_kee",50000);
  set("kee",50000);
  set("force",50000);
  set("max_force",20000);
  set("force_factor",60);
  set("gin", 50000);
  set("sen", 50000);
  set("max_gin", 50000);
  set("max_sen", 50000);
  set("combat_exp",4700000);
  set("chat_chance_combat", 32);
  set_skill("dodge",590);
  set_skill("move", 540);
  set_skill("parry",570);
  set_skill("unarmed",540);
  set("limbs", ({ "殭屍頭", "殭屍掌", "殭屍大腿" , "殭屍屁股"  }) );
  setup();
  set("default_actions", (: call_other, __FILE__,"query_action" :));
  reset_action();
  set_heart_beat(1);
  add_money("gold",100);
}

mapping query_action()
{
  return action[random(sizeof(action))];
}

void heart_beat()
{
  mixed all;
  object me,room,obj;
  int maxkee,kee,i,j,count;
  count = random(100);
  me = this_object();
  room = environment(me);
  if(!room) return ;
  if(!query("owner")) {
    message_vision(HIB + "\n跳啊跳的，跳到角落去躲起來。\n" + NOR,this_object());
    destruct(this_object());
    return;
  }
  all = all_inventory(room);
  if(count < 30 && me->is_fighting())
  {
    message_vision(me->query("name")+MAG"瘋狂的亂竄，四處饑渴的吸食鮮血。\n" + NOR,me);
    for( i = 0 ; i < sizeof(all) ; i++)
    {
      obj = all[i];
      if( obj->is_character() && !obj->is_corpse() && living(obj) && obj->query("id")!="zombie")
      {
        message_vision(HIR + "\n你被飛濺的血浪震攝住，也受到不小的衝擊。\n" + NOR,obj);
        obj->receive_damage("kee",420,me);
//        obj->add("kee",-420);
        obj->start_busy(1);
        COMBAT_D->report_status(obj, 1);
      }
    }
  }
  if(count < 20  && me->is_fighting())
  {
    message_vision(me->query("name")+HIR"兇性大發，對你" + HIR + "做出猛烈的攻擊！\n\n" + NOR,me);
    for( i = 0 ; i < sizeof(all) ; i++)
    {
      obj = all[i];
      if( obj->is_character() && !obj->is_corpse() && living(obj) && obj->query("id")!="zombie")
      {
        if( !me->query("crazy") )
          me->set("name","(" + HIR + "狂暴"NOR + ")"+me->query("name"));
        for(j=0;j<10;j++)
        {
          message_vision(HIK + "$N" + HIK + "被(" + HIR + "狂暴" + NOR + ")" + HIK + "殭屍狠狠抓中，滿身血痕！\n" + NOR,obj);
          if (obj->query("class")=="fighter" && obj->query_temp("keeup")==1)
            obj->receive_wound("kee",100+random(300),me);
          else if ((obj->query("class")=="prayer" && obj->query_temp("hwa_je")==1)
               || (obj->query("class")=="dancer" && obj->query_temp("ref_shield")==1)
               || (obj->query("class")=="dancer" && obj->query_temp("rainbow-steps")==1)
               || (obj->query("class")=="poisoner" && obj->query_temp("snake-steps")==1))
            obj->receive_wound("kee",100+random(200),me);      
          else
            obj->receive_wound("kee",100+random(100),me);
          me->set("crazy",1);
          COMBAT_D->report_status(obj, 1);
        }
        message_vision(HIB + "\n殭屍瘋狂的撕咬後，"NOR+me->query("name")+HIB"漸漸平靜下來。\n\n" + NOR,me);
        me->start_busy(1);
      }
    }
  }
  if( random(10) < 2 )
  {
    if( is_fighting() )
    {
      if( me->query("king") == 1 )
        me->set("name",HIK + "殭屍王" + NOR);
      else
        me->set("name",HIK + "殭屍" + NOR);

      if( query("kee") < query("eff_kee") )
        message_vision(HIK + "\n"+me->query("name")+HIK"身上發出耀眼的光芒，傷口似乎慢慢癒合了\n" + NOR,me);
      me->receive_heal("kee",1000);
      me->receive_heal("gin",1000);
      me->receive_heal("sen",1000);
      me->delete_busy();
      me->clear_condition();
    }
    else
    {
      if( query("eff_kee") < query("max_kee") )
        command("do 10 exert heal,!,!,!,10 exert recover");
      me->add("force",500);
    }
  }

::heart_beat();
}

string *filter_items = ({
  "light-emblem.c",
  "light_emblem.c",
  "emperor-stone.c",
  "emperor_stone.c",
  "fire-feather.c",
  "fire_feather.c",
  "free-shells.c",
  "free_shells.c",
  "kai-jade.c",
  "kai_jade.c",
  "forest-diamond.c",
  "forest_diamond.c",
  "fox-order.c",    
  "fox_order.c",
  "plum-wind.c",
  "plum_wind.c",
  "tender-charm.c",
  "tender_charm.c",
  "surname-yin.c",
  "surname_yin.c",
  "sakura-yin.c",
  "huai-yin.c",
  "black-crystal.c",
  "black_crystal.c",
  "banana-doll.c",
  "banana_doll.c",
});

string get_file_item()
{
  string *files,file,dir;
  string *dirs = ({
    "obj1",
    "obj2",
    "obj3",
    "obj4",
    "obj5",
    "obj6",
    "obj7",
    "obj8",
    "obj9",
    "obj10",
    "obj11",
    "obj12"
  });
  dir = "/open/sky/"+dirs[random(sizeof(dirs))]+"/";
  files = get_dir(dir);
  file = files[random(sizeof(files))];
  if(file[0] == '.') return get_file_item();
  if(member_array(file,filter_items) != -1 )
    return get_file_item();
  return dir+file;
}

void die()
{
  object winner = query_temp("last_damage_from");
  object me = this_object();
  object ob1,room,npc;
  string name;
  int kt,kk;
  kt = random(winner->query("zombie_kill")/2)+(winner->query("zombie_kill")/2);
  kk = winner->query("zombie_kill")/100;
  winner->add("zombie_kill",1);
  if( winner->query_temp("not_robot") < time() )
  {
    tell_object(winner,HIG + "你的太極防護之力已經消失了，被一陣毒氣逼出到殭屍洞外了。\n" + NOR);
    room = load_object(resolve_path(__DIR__,"../enter.c"));
    winner->move(room);
    destruct(me);
    return ;
  }
  // 2% 的掉寶率
  if( !me->query("have_item") 
      && random(1000) < (20+kk) 
      && query("owner") == winner )
  {
    string file = get_file_item();
    ob1=new(file);
    ob1->move(environment(me));
    me->set("have_item",1);
    name = winner->query("name");
    message_vision(HIM + "\n從"+me->name(1)+HIM"的身上掉下了一個「"+ob1->query("name")+HIM"」!!\n" + NOR,winner,me);
    CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s)	讓%s掉下了%s於 %s",winner->name(1),winner->query("id"),me->query("name"),ob1->query("name"),ctime(time())));
    write_file("/log/sky/zombie",sprintf("%s(%s)	讓%s掉下了%s於 %s\n",winner->name(1),winner->query("id"),me->query("name"),ob1->query("name"),ctime(time())));
  }

  if(query("owner") != winner)
  {
    winner->add_temp("not_robot",-1200);
    tell_object(winner,HIG + "殭屍噴出另一種毒氣，消減了你的太極之力。\n" + NOR);
  }
  room = load_object(resolve_path(__DIR__,sprintf("../room%02d.c",random(10)+1)));

  npc = new(__FILE__);
  npc->move(room);
  npc->set("owner",query("owner"));
  npc->set("nickname",query("owner")->name()+"的");
  if( (winner->query("zombie_kill")%10) == 0 && winner->query("zombie_kill") > 0 )
  {
    npc->set("max_gin",100000+kt*200);
    npc->set("eff_gin",100000+kt*200);
    npc->set("gin",100000+kt*200);
    npc->set("max_kee",100000+kt*200);
    npc->set("eff_kee",100000+kt*200);
    npc->set("kee",100000+kt*200);
    npc->set("max_sen",100000+kt*200);
    npc->set("eff_sen",100000+kt*200);
    npc->set("sen",100000+kt*200);
    npc->set("name",HIK + "殭屍王" + NOR);
    npc->set("combat_exp",10000000+random(winner->query("combat_exp")/10));
    npc->set("king",1);
  }else{
    npc->set("max_gin",50000+kt*100);
    npc->set("eff_gin",50000+kt*100);
    npc->set("gin",50000+kt*100);
    npc->set("max_kee",50000+kt*100);
    npc->set("eff_kee",50000+kt*100);
    npc->set("kee",50000+kt*100);
    npc->set("max_sen",50000+kt*100);
    npc->set("eff_sen",50000+kt*100);
    npc->set("sen",50000+kt*100);
  }
  message_vision(HIB + "\n一陣毒煙吹過～遠方傳來一陣叫聲～哈哈哈～我復活了～～～～。\n" + NOR,this_object());
  destruct(this_object());
}
