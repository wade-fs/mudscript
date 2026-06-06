//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/1/23

#include <ansi.h>
#include <command.h>
inherit NPC;
void create()
{
  set_name("華山蝶",({"girl hwa","girl","hwa"}) );
  set("long","她是銀針門門主華陀的義女，年繼雖然輕，不過已得乃父真傳。");
  set("gender","女性");
  set("class","doctor");
  set("combat_exp",700000);
  set("attitude","heroism");
  set("age",21);
  set("str",15);
  set("cor",40);
  set("per",30);
  set("int",30);
  set("force",2500);
  set("max_force",2500);
//  set("kee",2000);
  set_skill("literate",70);
  set("max_kee",2000);
  set_skill("cure",70);
  set_skill("dodge",80);
  set_skill("move",60);
  set_skill("parry",70);
  set_skill("stabber",60);
  set_skill("poison",50);
  set_skill("force",50);
  set_skill("yu-needle",80);
  set_skill("seven-steps",90);
  set_skill("godcure",70);
  set_skill("shinnoforce",65);
  map_skill("stabber","yu-needle");
  map_skill("dodge","seven-steps");
  map_skill("parry","yu-needle");
  map_skill("move","seven-steps");
  map_skill("force","shinnoforce");
  map_skill("cure","godcure");
  set("force_factor",10);
  set("chat_chance_combat",50);
  set("functions/break-kee/level",40);
  set("chat_msg_combat",({
    (: perform_action("stabber.break-kee") :),
  }));
  setup();
  carry_object("/open/doctor/obj/needle7.c")->wield();
  add_money("gold",10);
}

void init()
{ //兼查詢玩家本身存放了哪些doctor_book的關鍵道具
  add_action("do_raised","raised"); //領出該道具 //存入道具 使用接受道具來判別 //領出時才需付費 保管費
}

void greeting(object ob)
{
//增加quest判定 避免不分青紅皂白都下kill by blazakira
  if( (string)ob->query("class") == "poisoner" && !ob->query_temp("quests/doctor_book/check") &&
      !ob->query("quest/doctor_book/Lin_soul_splinters") &&
      !ob->query("quest/doctor_book/Star_soul_splinters") &&
      !ob->query("quest/doctor_book/Jing_soul_splinters") &&
      !ob->query("quest/doctor_book/Kui_soul_splinters") &&
      !ob->query("quest/doctor_book/Spica_soul_splinters") )
  {
    command("say 義父說見到魔教中人格殺勿論,納命來吧！");
    kill_ob(ob);
  }
  else if( (string)ob->query("class") == "poisoner")
  {
    command("arc "+ob->query("id"));
  }
}

int accept_object(object me, object ob)
{
  string object_name; //物品的名稱
  string object_id; //物品的名稱
  object_id=ob->query("id");
  object_name=ob->query("name");
  switch(object_id) { //先判斷收到物品的id
    case "lin soul splinters" :
      me->add("quest/doctor_book/Lin_soul_splinters",1);
      break;
    case "star soul splinters" :
      me->add("quest/doctor_book/Star_soul_splinters",1);
      break;
    case "jing soul splinters" :
      me->add("quest/doctor_book/Jing_soul_splinters",1);
      break;
    case "kui soul splinters" :
      me->add("quest/doctor_book/Kui_soul_splinters",1);
      break;
    case "spica soul splinters" :
      me->add("quest/doctor_book/Spica_soul_splinters",1);
      break;
    case "lin soul energy" :
      me->add("quest/doctor_book/Lin_soul_energy",1);
      break;
    case "star soul energy" :
      me->add("quest/doctor_book/Sta_soul_energy",1);
      break;
    case "jing soul energy" :
      me->add("quest/doctor_book/Jing_soul_energy",1);
      break;
    case "kui soul energy" :
      me->add("quest/doctor_book/Kui_soul_energy",1);
      break;
    case "spica soul energy" :
      me->add("quest/doctor_book/Spica_soul_energy",1);
      break;
    default :
      command("giggle");
      command("say 很對不起，我不能接受其他東西。");
      return 1;
      break;
  }
  command("say 是"+object_name+"嗎？我確實收下了。");
  destruct(ob);//交回物品得銷毀並免重複解的可行性的bug 放在此處則所有給予本npc的物品皆會刪除
  return 1;
}

int do_raised(string arg)
{
  object me=this_player(),ob;
  string str; 
  int a,b,c,d,e,f,g,h,i,j;
  a=me->query("quest/doctor_book/Lin_soul_splinters");
  b=me->query("quest/doctor_book/Star_soul_splinters");
  c=me->query("quest/doctor_book/Jing_soul_splinters");
  d=me->query("quest/doctor_book/Kui_soul_splinters");
  e=me->query("quest/doctor_book/Spica_soul_splinters");
  f=me->query("quest/doctor_book/Lin_soul_energy");
  g=me->query("quest/doctor_book/Sta_soul_energy");
  h=me->query("quest/doctor_book/Jing_soul_energy");
  i=me->query("quest/doctor_book/Kui_soul_energy");
  j=me->query("quest/doctor_book/Spica_soul_energy");

  str ="華山蝶說道﹕你存有以下\n";
  if(!arg) {
    if(a)
      str += "\t"WHT"麟"NOR"之碎片(lin soul splinters)共"HIG+a+NOR"個\n";
    if(b)
      str += "\t"CYN"星"NOR"之碎片(star soul splinters)共"HIG+b+NOR"個\n";
    if(c)
      str += "\t"MAG"井"NOR"之碎片(jing soul splinters)共"HIG+c+NOR"個\n";
    if(d)
      str += "\t"YEL"奎"NOR"之碎片(kui soul splinters)共"HIG+d+NOR"個\n";
    if(e)
      str += "\t"RED"角"NOR"之碎片(spica soul splinters)共"HIG+e+NOR"個\n";
    if(f)
      str += "\t"HIW"麟"NOR"之力(lin soul energy)共"HIG+f+NOR"個\n";
    if(g)
      str += "\t"HIC"星"NOR"之力(star soul energy)共"HIG+g+NOR"個\n";
    if(h)
      str += "\t"HIM"井"NOR"之力(jing soul energy)共"HIG+h+NOR"個\n";
    if(i)
      str += "\t"HIY"奎"NOR"之力(kui soul energy)共"HIG+i+NOR"個\n";
    if(j)
      str += "\t"HIR"角"NOR"之力(spica soul energy)共"HIG+j+NOR"個\n";
    str +="這些。\n\n";
    if(!a&&!b&&!c&&!d&&!e&&!f&&!g&&!h&&!i&&!j)
      tell_object(me,"華山蝶說道﹕很抱歉你什麼東西都沒有存在我這。\n\n");
    else
      tell_object(me,str);
    return 1;
  }

  switch(arg) { //一次給一個
    case "lin soul splinters" :
      if(a>0) {
        me->add("quest/doctor_book/Lin_soul_splinters",-1);
        ob=new("/open/doctor/doctor_book/obj/scrap");
        ob->set("sort","麟");
      }
      break;
    case "star soul splinters" :
      if(b>0) {
        me->add("quest/doctor_book/Star_soul_splinters",-1);
        ob=new("/open/doctor/doctor_book/obj/scrap");
        ob->set("sort","星");
      }
      break;
    case "jing soul splinters" :
      if(c>0) {
        me->add("quest/doctor_book/Jing_soul_splinters",-1);
        ob=new("/open/doctor/doctor_book/obj/scrap");
        ob->set("sort","井");
      }
      break;
    case "kui soul splinters" :
      if(d>0) {
        me->add("quest/doctor_book/Kui_soul_splinters",-1);
        ob=new("/open/doctor/doctor_book/obj/scrap");
        ob->set("sort","奎");
      }
      break;
    case "spica soul splinters" :
      if(e>0) {
        me->add("quest/doctor_book/Spica_soul_splinters",-1);
        ob=new("/open/doctor/doctor_book/obj/scrap");
        ob->set("sort","角");
      }
      break;
    case "lin soul energy" :
      if(f>0) {
        me->add("quest/doctor_book/Lin_soul_energy",1);
        ob=new("/open/doctor/doctor_book/obj/scrap2");
        ob->set("sort","麟");
      }
      break;
    case "star soul energy" :
      if(g>0) {
        me->add("quest/doctor_book/Sta_soul_energy",1);
        ob=new("/open/doctor/doctor_book/obj/scrap2");
        ob->set("sort","星");
      }
      break;
    case "jing soul energy" :
      if(h>0) {
        me->add("quest/doctor_book/Jing_soul_energy",1);
        ob=new("/open/doctor/doctor_book/obj/scrap2");
        ob->set("sort","井");
      }
      break;
    case "kui soul energy" :
      if(i>0) {
        me->add("quest/doctor_book/Kui_soul_energy",1);
        ob=new("/open/doctor/doctor_book/obj/scrap2");
        ob->set("sort","奎");
      }
      break;
    case "spica soul energy" :
      if(j>0) {
        me->add("quest/doctor_book/Spica_soul_energy",-1);
        ob=new("/open/doctor/doctor_book/obj/scrap2");
        ob->set("sort","角");
      }
      break;
    default : //不符合道具關鍵字時的反應
      command("giggle");
      command("say 抱歉，這東西目前並不是我的保管範圍。");
      return 1;
      break;
  }
  if(!ob) //符合道具關鍵字時的反應
    command("say 疑？這東西你沒有寄放在我這裡呀。");
  else {
    if(!me->pay_money(100000)) {
      tell_object(me,CYN"華山蝶說道﹕你身上錢不夠付保管費，最少也要十兩黃金。\n"NOR);
      return 1;
    }
    ob->move(me);
    command("say 是一枚"+ob->query("name")+"嗎？確實交到你手上了，並跟你酌收十兩黃金，謝謝。");
  }
  return 1;
}

void die()
{    
  object winner = query_temp("last_damage_from");
  int j;

  if(!winner)
  {
    ::die();
    return ;
  }

  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {      
        new("/open/sky/obj8/spring_wind")->move(environment(winner));
        message_vision(HIM"\n從華山蝶的身上掉下了一件奇怪的東西!!\n"NOR,winner);
        write_file("/log/sky/obj8/spring_wind",sprintf("%s(%s) 讓華山蝶掉下了春情風於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    }else{
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
      {      
        new("/open/sky/obj8/spring_wind")->move(environment(winner));
        message_vision(HIM"\n從華山蝶的身上掉下了一件奇怪的東西!!\n"NOR,winner);
        write_file("/log/sky/obj8/spring_wind",sprintf("%s(%s) 讓華山蝶掉下了春情風於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  ::die();
}
