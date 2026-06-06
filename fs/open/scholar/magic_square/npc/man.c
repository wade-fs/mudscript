// /open/center/npc/vendor.c
#include <obj.h>
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
object *stones;
void create_room_link(int times);
int check();
void confuse1(object me)
{

  message_vision(CYN"$N說道：好啦，你已經會了 你該回去了！離開身體太久有可能會回不去哦。\n"NOR,this_object());
  me->move("/open/scholar/room/house");
  message_vision(CYN"$N隨手拿了一隻筆和竹簡把剛剛陳平師叔說的話記下來！\n"NOR,me);
  new("/open/scholar/magic_square/obj/paper.c")->move(me);
}
string quest1()
{
  return "這個陣圖是一個有趣的問題，他的行列與斜的加總，都要為一樣的，石頭上有數字，你可以用 push 來推動它。！\n";
}
string check_square()
{
  if(check() == 1 ) 
  {
    this_player()->set_temp("quests/confuse",11);
    call_out("confuse1",2,this_player());
  return "嗯，沒問題了，沒想到你這麼輕鬆解決我的問題！哪我把拋磚引玉之計教你，你得記好！\n";
  }
  else
  {
     create_room_link(3);
    return "什麼鬼！！你到底會不會解啊！不要再亂排了！這不是正確的排法！\n";
  }
}
void create()
{
      set_name("陳平", ({ "chen pin", "chen" ,"pin"}) );
      set("long","他一直坐在哪，看著四周的環境，不停的思索這個問題要怎麼解決。\n");
        set("attitude", "friendly");
        set("combat_exp",30000000);
        set("inquiry",([
              "問題" : (:quest1:),
              "檢查" : (: check_square:),
              "陣圖" : "傳說中，把石頭依一些規則放置於各個房間，可以讓敵人迷惑，而不知身處何處。\n"+
                       "此處總共有九個房間，而地上有各種數字的石頭，要讓他直的、衡的、斜的總合都要一致。",
              "石頭" : "石頭上都有數字哦，你可以仔細的看一下，你可以推動(push)石頭。",
              ]));

        set_temp("apply/dodge",500);
        set_temp("apply/parry",500);
        setup();
}
void init()
{
  object ob = previous_object();
  call_out("greeting", 1, ob);
  ::init();
}
void greeting(object ob)
{
  if(ob->query_temp("quests/confuse") == 10)
  {
    message_vision(HIC"$N說道：如果解決的話，就請我幫你「檢查」吧！\n"NOR,this_object());
  }
  else
  {
     message_vision(HIR"$N說道：沒想到，你竟然進來我的夢中了，而在這裡我一直遇到一個陣圖的問題，所以我才一直不醒。\n"NOR,this_object());
     create_room_link(3);
     ob->set_temp("quests/confuse",10);
  }
  ::greeting();
}
void create_room_link(int times)
{
  string home;
  int k = 0;
  stones = allocate(0);
  k = 0;
  for(int i = 1 ; i <= times ; i++)
  {
    for(int j = 1; j <= times ; j++)
    {
      object obj = load_object("/open/scholar/magic_square/"+i+"-"+j+".c");
      obj->delete("exits");
      foreach(object s in all_inventory(obj))
      {
        if(s->query("stone")) destruct(s);
      }
      if(i - 1 > 0 ) obj->set("exits/west","/open/scholar/magic_square/"+(i-1)+"-"+j);
      if(j - 1 > 0 ) obj->set("exits/north","/open/scholar/magic_square/"+(i)+"-"+(j-1));
      if(i + 1 <= times ) obj->set("exits/east","/open/scholar/magic_square/"+(i+1)+"-"+j);
      if(j + 1 <= times ) obj->set("exits/south","/open/scholar/magic_square/"+(i)+"-"+(j+1));
    }
  }
  if(times == 3)
  {
    switch(random(4))
    {
      case 0:
        home = "/open/scholar/magic_square/2-1";
        break;
      case 1:
        home = "/open/scholar/magic_square/3-2";
        break;
      case 2:
        home = "/open/scholar/magic_square/1-2";
        break;
      case 3:
        home = "/open/scholar/magic_square/2-3";
        break;
      default:
    }
  }
  else
  {
    home = "/open/scholar/magic_square/"+(random(times)+1)+"-"+(random(times)+1);
  }
  for(int i = 1 ; i <= times ; i++)
  {
    for(int j = 1; j <= times ; j++)
    {
      object stone;
      k++;
      stone = new("/open/scholar/magic_square/obj/stone.c");
      stone->set_name(CHINESE_D->chinese_number(k)+ "號石",({ k+"'s stone","stone",""+k}) );
      stone->set("stone",k);
      stones += ({ stone });
      stone->move(home);
    }
  }
  stones[0]->move(home);
  stones[0]->set("no_push",1);
  this_object()->move(home);
  this_player()->move(home);
  message_vision(YEL"一陣煙霧環繞$N與$n，整個魔方陣的陣型已經改變了。\n"NOR,this_object(),this_player());
  set("times",times);
}
int check()
{
  int last;
  int *sum;
  object obj;
  int times = query("times");
  
  sum = allocate(times*2+2);
  last = -1;
  for(int i = 1 ; i <= times ; i++) // 算橫的
  {
    last++;
    sum[last] = 0;
    for(int j = 1; j <= times ; j++)
    {
        obj = present("stone",load_object("/open/scholar/magic_square/"+i+"-"+j+".c"));
        if(!obj) return 0;
        sum[last] += obj->query("stone");
    }
  }
  for(int i = 1 ; i <= times ; i++) // 算直的
  {
    last++;
    sum[last] = 0;
    for(int j = 1; j <= times ; j++)
    {
        obj = present("stone",load_object("/open/scholar/magic_square/"+j+"-"+i+".c"));
        if(!obj) return 0;
        sum[last] += obj->query("stone");
    }
  }
  last++;
  sum[last] = 0;

  for(int i = 1 ; i <= times ; i++) // 算斜的
  {
    obj = present("stone",load_object("/open/scholar/magic_square/"+i+"-"+i+".c"));
    if(!obj) return 0;
    sum[last] += obj->query("stone");
  }
  last++;
  sum[last] = 0;

  for(int i = 1 ; i <= times ; i++) // 算斜的
  {
    obj = present("stone",load_object("/open/scholar/magic_square/"+(times-i+1)+"-"+i+".c"));
    if(!obj) return 0;
    sum[last] += obj->query("stone");
  }
  last = sum[0];
  foreach(int i in sum)
  {
    if(last != i ) return 0;
  }
  return 1;
}
