// test_officer.c
// rewrite by wade in 1/5/1996 for heart_beat 方式
//取test_men_data陣列時 偶爾會出問題 先改用delete做設定 by blazakira 2011/4/11

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
//#include <capital.h>

#define PREPARE 300
#define START 330
#define END 350
#define REPORT 400
string do_help();
int time=290;

mapping test_men_data = ([
  "漂漂玟玟":200,
  "蘇東坡": 120,
  "張載": 70,
  "王安石": 90,
  "司馬光": 100,
  "程郢": 20,
  "程顥": 80,
  "辛棄疾": 100,
  "傅劍寒": 150,
  "陸九淵": 80,
  "朱熹": 110,
  "王評": 30,
  "張九": 25,
  "陳詩和": 60,
  "林賦": 65,
  "張秀豐": 70,
  "范光": 75,
  "郭奉孝": 301,
  "吳擎": 80,
  "王軌": 70,
  "起毛球": 100,
  "公孫聖凡": 90,
  "歐陽離否": 80,
  "慕容常": 15,
  "慕容青": 85,
  "鷹宮‧真": 130,
  "周公瑾": 240,
  "王鳳": 70,
  "香蕉娃娃工": 500,
  "守夜人": 250,
  "淒涼星空" : 350,
  "東尼東尼‧喬巴": 200,
  "巫妖三日": 180, //我是來亂的(笑 by blazakira
]);

void create()
{
  seteuid(getuid());
  set_name("嚴大人",({"test officer","officer","master"}));
  set("long","負責帝國考試的主考官,你可以用 join 來加入考試,\n"+
    "考上的人也可用 report 來加入官職,注意: 一但加入\n"+
    "官職,即放棄原門派,千萬慎重!!\n");
  set("gender","男性");
  set("title","主考官");
  set("age",56);
  set("time",0);
  set("test_men",([]));
  set("set_test_men",([]));
  set("new_officer",([]));
  set("test_men_id",([]));
  set("chat_chance",15);
  set("class","officer");
  set("officer_class","主考官");
  set("max_officer_power",100);
  set("officer_power",100);
  set("max_kee", 10000);
  set("inquiry", ([
    "幫忙" : (: do_help :),
  ]) );
  setup();
}

int accept_object(object me,object ob)
{
  string letter_id;
  letter_id=ob->query("id");
  if(letter_id=="test_letter")
  {
    destruct(ob);
    command("say 咦!我的信，嗯......多謝你啦");
    command("bow"+me->query("id"));
    me->add("taigan_exp",10);
    me->delete_temp("working");
    switch(random(3)){
      case 1:
        me->set("taigan_work",6);
        break;
      case 2:
        me->set("taigan_work",7);
        break;
      case 3:
        me->set("taigan_work",8);
        break;
    }
  }
  else{
    command("say 嗯???這信不是給我的，你搞錯囉!!!");
    command("give"+ob->query("id")+me->query("id"));
  }
}

string do_help()
{
  int work,i,j,k;
  object me,ob,letter;
  me=this_player();
  ob=this_object();
  work=me->query("taigan_work");
  if(work!=5 || me->query_temp("working"))
    return "我現在沒什麼事需要你幫忙，去看看別人需不需要吧。\n";
  else
  {
    switch(random(3))
    {
      case 1:
        new("/open/capital/room/sroom/obj/soldier_letter")->move(me);
        me->set_temp("working",1);
        message_vision("給了$N一封信。\n",me);
        return "你來的正好，我這裡有封信要交給軍機處的掌兵使，你幫我跑一趟吧。\n";
        break;
      case 2:
        new("/open/capital/room/sroom/obj/lee_letter")->move(me);
        me->set_temp("working",1);
        message_vision("給了$N一封信。\n",me);
        return "你來的正好，我這裡有封信要交給戰情室的李大人，你幫我跑一趟吧。\n";
        break;
      case 3:
        new("/open/capital/room/sroom/obj/wu_letter")->move(me);
        me->set_temp("working",1);
        message_vision("給了$N一封信。\n",me);
        return "你來的正好，我這裡有封信要交給糧草總兵吳大人，你幫我跑一趟吧。\n";
        break;
    }
  }
}

void init()
{
  add_action("join_test","join");
  add_action("join_guild","report");
  ::init();
  call_out("greeting", 3, this_player());
}

void greeting( object ob ) {
  set_heart_beat(1);
}

void do_prepare()
{
  CHANNEL_D->do_channel(this_object(), "mud",HIY + "\n從京城裡傳來消息﹕\n秋試即將開始了.....\n" + NOR);
}

int query_test()
{
  write ("time is "+time+".\n");
  return time;
}

void do_start()
{
  mapping dict2;
  string *name3;
  string test_men_name;
  int i;
  set("test_men_id",([]));
  CHANNEL_D->do_channel(this_object(), "mud",HIG + "\n從京城裡傳來消息﹕\n秋試正式開始了....!!!\n" + NOR);
  command("say 現在請各位要參加考試的考生開始考試(join)。");
  dict2=query("set_test_men");
  for(i=0;i<3;i++)
  {
    name3=keys(test_men_data);
/*
魚缸@台北 說 (下午 11:52):
因為他的name3 的長度和 teat_mem_data 的長度不一樣
魚缸@台北 說 (下午 11:52):
random 超出陣列值
魚缸@台北 說 (下午 11:55):
用 random (sizeof(name3))就好了啊
魚缸@台北 說 (下午 11:57):
前面的name3 也是個array
魚缸@台北 說 (下午 11:57):
反正他只要是radnom 一個name3
*/

    test_men_name=name3[random(sizeof(test_men_data))];
//    test_men_name=name3[random (sizeof(name3))];
    dict2[test_men_name]=test_men_data[test_men_name];
    dict2[test_men_name]=random(random(dict2[test_men_name]));
    dict2[test_men_name]+=10+5*i;
    map_delete(test_men_data,test_men_name);
  }
  dict2=query("test_men_id");
  dict2["1"]=1;dict2["2"]=1;dict2["3"]=1;
  set("test_men_id",dict2);
}

void do_end()
{
  CHANNEL_D->do_channel(this_object(), "mud",HIC + "\n從京裡傳來消息﹕\n秋試結束了.....\n" + NOR);
  command("say 好了 ! 考試時間到了。\n");
}

void do_report()
{
  mapping dict1,dict2;
  string *name1,*name2;
  string  msg;
  string test_men_name;
  int i,th1,th2,th3;

  dict1=query("test_men");
  dict2=query("set_test_men");
  name1=keys(dict1);
  name2=keys(dict2);
  if (!name2 || sizeof(name2) == 0) return;
  th1=0;th2=0;th3=0;
  for(i=0;i<sizeof(dict2);i++)
    if(dict2[name2[i]]>dict2[name2[th1]])
      th1=i;
  if(th1==0) th2=1;
    for(i=0;i<sizeof(dict2);i++)
      if(dict2[name2[i]]>dict2[name2[th2]]&&i!=th1)
        th2=i;
  if(th1==0||th2==0) th3++;
    if((th1==1||th2==1)&&th3==1) th3++;
      for(i=0;i<sizeof(dict2);i++)
        if(dict2[name2[i]]>dict2[name2[th3]]&&i!=th1&&i!=th2)
          th3=i;
  msg =
    HIR + "從京裡傳來的消息﹕\n秋試結果﹕.....\n狀元﹕"+
    name2[th1]+"\n榜眼﹕"+name2[th2]+"\n探花﹕"+name2[th3]+"\n";
    msg += "落榜者﹕\n";
  for(i=0;i<sizeof(dict1);i++)
    if(name2[th1]!=name1[i]&&name2[th2]!=name1[i]&&name2[th3]!=name1[i])
            msg += name1[i]+"\n";
  msg += HIY + "考取者請儘速來報到(report)\n" + NOR;
  CHANNEL_D->do_channel(this_object(), "mud", msg);
  dict1=([]);
  dict2=query("test_men_id");
  name1=keys(query("set_test_men"));
  dict1[1]=dict2[name1[th1]];
  dict1[2]=dict2[name1[th2]];
  dict1[3]=dict2[name1[th3]];
  set("new_officer",dict1);
  set("test_men",([]));
  set("set_test_men",([]));

  time = 0;
}

int join_test()
{
  mapping dict;
  object  me=this_player();
//  set_heart_beat(1);

  if (time < START || time >= END)
    return notify_fail("秋試尚未開始﹐請你再等等吧。\n");
  if(me->query_skill("literate",1)==0)
    return notify_fail("文盲也來考試？\n");
  if(me->query("family/family_name")=="魔刀門")
    return notify_fail("你所屬門派不能當官喔。\n");
  if(me->query("family/family_name")=="魔刀莫測")
    return notify_fail("你所屬門派不能當官喔。\n");
  if(me->query("family/family_name")=="丐幫")
    return notify_fail("你所屬門派不能當官喔。\n");
  if(me->query("family/family_name")=="血魔一派")
    return notify_fail("你所屬門派不能當官喔。\n");
  if(me->query("return_sha"))
    return notify_fail("你效命過血魔不能當官喔。\n");

  if(me->query("class")=="prayer")
    return notify_fail("你所屬門派不能當官喔。\n");
  dict=query("test_men");
  if(dict[me->query("name")]!=0)
    return notify_fail("你不是已經報名考試了嗎？\n");
  if(me->query("officer_class"))
    return notify_fail("你不是當過官了嗎？再報名考試就是犯了欺君之罪。\n");
  message_vision(CYN + "$N說道﹕我要參加考試 !\n" + NOR,me);
  if(me->query("class")=="officer")
  {
    command("say 大人 ! 別跟我開玩笑了。");
    return 1;
  }
  command("nod");
  dict=query("test_men");
  dict[me->query("name")]=random(me->query_skill("literate",1));
  dict=query("set_test_men");
  dict[me->query("name")]=random(me->query_skill("literate",1));
  dict=query("test_men_id");
  dict[me->query("name")]=me->query("id");
  return 1;
}

int join_guild()
{
  mapping dict=query("new_officer");
  object  me=this_player();
  int i;

  if(me->query("class")=="officer")
    return notify_fail("你已經是官了。\n");
  for(i=1;i<=3;i++)
    if(me->query("id")==dict[i])
    {
      message_vision("$N考取了功\名﹐當了個小官。\n(詳細說明請參閱help officer)\n",me);
      me->set("class","officer");
      me->set("officer_class","小官");
      me->delete("family");
      me->delete_skill("sha-array");
      me->delete("marks/仙劍七俠");
      return 1;
    }
  command("say 對不起 ! 你並沒考上﹐加油吧﹐下次再來﹐別氣餒 !!");
  return 1;
}

void heart_beat()
{
  if (time == PREPARE) do_prepare();
  else if (time == START) do_start();
  else if (time == END) do_end();
  else if (time == REPORT) do_report();

  time++;

  ::heart_beat();
}
