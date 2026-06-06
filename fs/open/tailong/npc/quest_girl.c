#include <ansi.h>
inherit NPC;
string do_game();
string ask_title();
void create()
{
        seteuid(getuid());
        set_name("小女孩",({"little girl","girl"}));
        set("long",@LONG
一個小女孩，獨自一個人在玩遊戲，看起來好孤獨，好可憐喔!!
LONG);
        set("gender","女性");
        set("combat_exp", 1000);
        set("attitude","friendly");
        set("age",12);
        set("force",5000);
        set("max_force",5000);
        set("kee",1000);
        set("max_kee",1000);
        set("force_factor",30);
        set("inquiry", ([
        "玩遊戲" : (: do_game :),
         "稱號":(: ask_title :),
        ]));
        set("chat_chance", 5);
        set("chat_msg", ({
        "小女孩道: 唉!一個人玩遊戲真無聊，都沒有人可以陪我玩。\n",
        }));
        setup();
}
void init()
{
  object ob;
    add_action("do_answer","answer");
  if(interactive(ob =this_player())) {
  call_out("greeting",1,ob);
  }
}

string ask_title()
{
object me=this_player();
if(me->query("get-evil-mblade") && me->query("title") != HIG"妖"HIW"刀"HIG"傳"HIR"人"NOR)
{
me->set("title",HIG"妖"HIW"刀"HIG"傳"HIW"人"NOR);

return "修正完畢\n";
//return 0; <--變成不跑
}
if(me->query("mk-blade"))
{
command("say 我來幫你檢查看看吧...\n");
if(me->query("gender")=="男性" && me->query("title")!=HIW"漩羽"HIY"刀皇"NOR)
{
me->set("title",HIW"漩羽"HIY"刀皇"NOR);
message_vision(HIW"\n白光散去$N的稱號修正完畢。\n"NOR,me); 
return "修正完畢";
}
else if(me->query("gender")=="女性" && me->query("title")!=HIB"刀魂"HIC"幽姬"NOR)
{
me->set("title",HIB"刀魂"HIC"幽姬"NOR);
message_vision(HIW"\n白光散去$N的稱號修正完畢。\n"NOR,me);
return "修正完畢";
}
}
return "你不需要修正";
}
int set_number()
{
    int i,s,j,flag,num,sub,temp,k;

    num=0;
    for(i=0;i<4;i++){
      s=random(10);
      sub=1;
      for(j=0;j<i;j++)
        sub*=10;
      if(i){
        flag=0;
        temp=sub;
        k=num;
        do{
          temp/=10;
          if((k/temp)==s)
            flag=1;
          else
            k=k%temp;
        }while(temp>1);
        if(flag){
         i--;
         continue;
        }
      }
      num+=s*sub;
    }
    return num;
}
string do_game()
{
    object ppl=this_player();
    int num;
    string number;
    if(ppl->query("guest_time") > time())
      return "哎唷，猜哪麼快，機器人逆。\n";
    if(ppl->query_temp("number_quest"))
      return "你正在跟我玩阿!!!\n";
    if(ppl->query("t_standby")>=ppl->query("max_standby"))
      return "很抱歉，你曾經擁有的替身總數已達上限，所以不能跟我玩遊戲。\n";
    if(ppl->query("standby")>=1)
      return "很抱歉，你現在擁有足夠的替身，等你真的有需要替身再來陪我玩遊戲吧。\n";
    number="";
    num=set_number();
    if(num<1000)
      number+="0";
    number+=sprintf("%d",num);
    ppl->set_temp("number_quest/number",number);
    tell_object(ppl,"小女孩說道:你要跟我玩遊戲嗎，真是太好了!!!\n");
    tell_object(ppl,"小女孩說道:那我們現在來玩猜數字遊戲。\n");
    tell_object(ppl,"小女孩說道:我會從"HIY"０～９"NOR"選四個不重覆的數字讓你猜?\n");
    tell_object(ppl,"小女孩說道:如果你猜的數字中有一個位置是正確的，我會說["HIR"一陽"NOR"]。\n");
    tell_object(ppl,"小女孩說道:如果有一個你猜的數字對，但是位置不正確，我會說["HIC"一陰"NOR"]。\n");
    tell_object(ppl,"小女孩說道:這樣反覆讓你猜，如果是["HIR"四陽"NOR"]，完全猜中了，我會送你一個小禮物。\n");
    tell_object(ppl,"小女孩說道:你想不想跟我玩呢"HIG"(answer yes/no)"NOR"?\n");
    return "";
}
int do_answer(string arg)
{
    object ppl=this_player();
    int num,i,a,b,s,sub,temp,k,j,time;
    string ans,txt;
    string out="";

    if(!arg) return 0;
    if(!ppl->query_temp("number_quest")) return 0;
    if(!ppl->query_temp("number_quest/time")){
      if(arg=="yes"){
        tell_object(ppl,"小女孩說道:你要跟我玩?!太好了。\n");
        tell_object(ppl,"小女孩說道:我已經想好數字了，你開始猜吧(answer 數字)。\n");
        ppl->add_temp("number_quest/time",1);
        ppl->set("guest_time",time()+60); // 暫定一分鐘，正常玩家不會遇到這個困擾
        return 1;
      }
      else if(arg=="no"){
        tell_object(ppl,"小女孩說道:原來你不想玩......我懂了。\n");
        ppl->delete_temp("number_quest");
        command("cry");
        return 1;
      }
      else return 0;
    }
    else{
      tell_object(ppl,HIG"你說:我猜"+arg+"。\n"NOR);
      if(sizeof(arg)!=4){
        tell_object(ppl,"你要回答的是四位數字啦!!\n");
        return 1;
      }
      ppl->add_temp("number_quest/time",1);
      for(i=0;i<4;i++){
        txt=arg[i..i];
        sscanf(txt,"%d",num);
        if(num< 0 || num > 9){
          tell_object(ppl,"你要回答的是四位數字啦!!\n");
          return 1;
        }
      }
      for(i=0;i<3;i++)
        for(j=i+1;j<4;j++)
          if(arg[i]==arg[j]){
            tell_object(ppl,"是要猜四個不重覆的數字喔!!\n");
            return 1;
          }
      ans=ppl->query_temp("number_quest/number");
      a=0;
      for(i=0;i<4;i++)
        if(ans[i]==arg[i]) a++;
      b=0;
      for(i=0;i<4;i++)
        for(j=0;j<4;j++)
          if(i==j) continue;
          else if(ans[i]==arg[j]) b++;
      if(!a && !b) out="都沒猜到";
      else{
       if(a) out+=HIR+CHINESE_D->chinese_number(a)+"陽"+NOR;
       if(b) out+=HIC+CHINESE_D->chinese_number(b)+"陰"+NOR;
      }
      tell_object(ppl,"["+out+"]。\n");
      if(a==4){
        command("say "+ppl->query("name")+"好厲害喔，猜到了。");
        command("say 剛剛幫你算了一下，你總共猜了"+
          CHINESE_D->chinese_number(ppl->query_temp("number_quest/time")-1)+"次。");
        time=ppl->query_temp("number_quest/time")-1;
       /*2002-12-29 --kalin
           恢復fanset..所以不用猜謎，但是加上3次以內猜中可以獲得替身1
                if(time<=7){
          command("say 看在你那麼厲害的份上，讓你可以使用喚雲扇的fanset功\能!!");
          ppl->set_temp("can_fanset",1);
        }
                */
                if(time<=3){
          command("say 看在你那麼厲害的份上，送你一個替身!!");
          if(time == 3)   ppl->add("t_standby",1);
          ppl->add("standby", 1);
          log_file("guess_stdby", sprintf("%s(%s) 猜數字%d次得到替身於 %s\n"
                   ,ppl->query("name"),ppl->query("id"), time, ctime(time()) ));
        }
        else{
          command("say 給你獎品，kiss 一個。");
          command("lkiss "+ppl->query("id"));
          
        }
        command("smile");
        ppl->delete_temp("number_quest");
      }
      return 1;
    }
    return 0;
}
