// By Guetenr 魔教徒用毒囊袋 2009.9

#include <ansi.h>
#include "/open/open.h"
inherit ITEM;
string TITLE="[毒囊袋]";
string DESTRUCT_MESSAGE=TITLE+"並不是你的, 別亂用哩!!\n";
object me=this_player();
object ob=this_object();
mapping valid_types = ([
        "faint poison":           "一刻香",
        "rose poison":            "火玫瑰毒",
        "five poison":            "五毒",
        "dark poison":            "深宮奇毒",
        "scorpion poison":        "蠍毒",

]);
 
void create()
{
      set_weight(0);
      if( clonep() )
           set_default_object(__FILE__);
      else {
           set("unit","個");
           set("long","這是魔教徒用來放置毒藥用的袋子, 魔教徒通常會將平時取得的毒藥"+
           "放置於此袋中。\n"+
           "鍵入<help poison_bag>可獲得更多的資訊。");
           set("value",0);
           set("no_drop",1);
           set("no_get",1);
           set("no_put",1);
           set("no_give",1);
           }
      set("belong",getuid(me));
      setup();
}
 
void init()
{
        if(!query("belong")){
           if(userp(environment())) set("belong",geteuid(environment()));
        }
        set_name(me->name(1)+ "的" + HIG + "毒囊袋" + NOR, ({ "poison_bag" }));
        add_action("do_gather","gather");
        add_action("do_list","list");
        add_action("do_take","take");
        add_action("do_help","help");
}
int do_help(string str)
{
        if (str!="poison_bag") return 0;
        write(@Help
 
        你可以使用以下的幾個命令:
        gather <數量> <poison>          存放毒物。
        list poison_bag                 檢查毒囊中毒物存量。
        take <數量> <poison>            由毒囊袋取出毒物。

        PS:拿毒時請注意拿不拿得動, 拿不動還硬拿到時發生什麼事, 
           可別叫天神幫你哩(奸笑)
 
Help
        );
        return 1;
}
int do_take(string str)
{
        int amount,before,now,now2;
        object obj1,obj2,obj3,obj4,obj5,poison_type,poison_now;
        string item2;
        obj1 = new( "/obj/poison/faint_poison" );
        obj2 = new( "/obj/poison/rose_poison" );
        obj3 = new( "/obj/poison/five_poison" );
        obj4 = new( "/obj/poison/dark_poison" );
        obj5 = new( "/obj/poison/scorpion_poison" );
        if(me->query("id") != this_player()->query("id") ||
           ob->query("belong") != environment(this_object())->query("id"))
           {
           write(DESTRUCT_MESSAGE); 
           destruct(ob);                          return 1;
           }         
        if(str == 0 )
          return notify_fail(TITLE+"存什麼?\n");
        if( me->query("class")!= "poisoner")
          return notify_fail(TITLE+"對於不是魔教徒的人來說, 這只是一個爛袋子。\n");                                              
        if (sscanf (str,"%d %s",amount,item2)==2)
        {
                before = me->query("poison_bag/"+item2);     
                poison_now = present(item2,me);        
                if(undefinedp(valid_types[item2]) )
                   return notify_fail(TITLE+"你只能拿毒而已吧??\n");
                if( me->query_skill("poison",1) < 100 )
                   return notify_fail(TITLE+"對於下毒技巧不足的人, 是不給用的。\n");
                if (amount > before)
                   return notify_fail("你並沒有存這麼多毒哩。\n" + NOR);
                if(amount <= 0)
                   return notify_fail("別鬧了, 這樣你是要怎麼拿啊！\n" + NOR);  
                if(item2 == "faint poison")             { poison_type = obj1; } 
                  else if(item2 == "rose poison")       { poison_type = obj2; }
                  else if(item2 == "five poison")       { poison_type = obj3; }
                  else if(item2 == "dark poison")       { poison_type = obj4; }
                  else if(item2 == "scorpion poison")   { poison_type = obj5; }
                  else return notify_fail("你打算拿什麼東西出來用啊??\n" + NOR);
                if(!poison_now)
                {
                 poison_type->move(me);
                 poison_type->set_amount(amount);
                 message_vision("$N將"+chinese_number(amount)+poison_type->query("unit")+poison_type->query("name")+"取了出來。\n",me);
                 me->set("poison_bag/"+item2,before-amount);
                }
                else
                {
                now = poison_now->query_amount();
                poison_type->move(me);
                poison_type->set_amount( now + amount );       
                message_vision("$N將"+chinese_number(amount)+poison_type->query("unit")+poison_type->query("name")+"取了出來。\n",me);
                me->set("poison_bag/"+item2,before-amount);
                }
                return 1;
         }  
                return 0;
}
int do_gather(string str)
{
        int poison_a,poison_amount,i;
        object obj;
        string item;

        if(me->query("id") != this_player()->query("id"))
        {
          destruct(ob);
          return notify_fail(DESTRUCT_MESSAGE);
        }
        if(str == 0 )
          return notify_fail(TITLE+"存什麼?\n");
         if( me->query("class")!= "poisoner")
          return notify_fail(TITLE+"對於不是魔教徒的人來說, 這只是一個爛袋子。\n");
        if( me->query_skill("poison",1) < 100 )
          return notify_fail(TITLE+"對於下毒技巧不足的人, 是不給用的。\n");
        if (sscanf (str,"%d %s",poison_a,item)==2)
        {
                obj = present(item,me);
                if(!obj)   
                   return notify_fail(TITLE+"你的身上沒有這個東西哩。\n");
                if(undefinedp(valid_types[item]) )
                   return notify_fail(TITLE+"你只能把毒放在毒囊袋而已說。\n");
                if (poison_a > obj->query_amount())
                   return notify_fail("你並沒有這麼多"+obj->query("name")+"。\n" + NOR);
                if(poison_a <= 0)
                   return notify_fail("別鬧了, 這樣你是要怎麼放啊！\n" + NOR); 
                if(obj->query_amount() - poison_a  <= 0)
                   {
                    message_vision("$N將身上全部的"+obj->query("name")+"放置於毒囊袋中。\n",me);
                    destruct(obj);
                    me->set("poison_bag/"+item,me->query("poison_bag/"+item) + poison_a);
                    return 1;                          
                   }
                   obj -> set_amount( obj->query_amount() - poison_a );       
                   message_vision("$N將"+chinese_number(poison_a)+obj->query("unit")+obj->query("name")+"放置於毒囊袋中。\n",me);
                   poison_amount = me->query("poison_bag/"+item) + poison_a;
                   me->set("poison_bag/"+item,poison_amount);
                   return 1;
         }  
                   return 0;
}

int do_list(string str)
{
        int i;
        mapping poison_bag_number;
        string *poison_name;
        if( str != "poison_bag" )
          return 0;
        if(me->query("id") != this_player()->query("id"))
        {
          destruct(ob);
          return notify_fail(DESTRUCT_MESSAGE);
        }
        if( sizeof(me->query("poison_bag")) == 0 )
          return notify_fail(TITLE+"毒囊袋中還什麼東西都沒有。\n");
        poison_bag_number=me->query("poison_bag");
        poison_name=keys(poison_bag_number);
        write(TITLE+"以下是毒囊袋中毒物的存量。\n");
        write("     名稱                數量\n");
        for(i=0; i<sizeof(poison_name); i++)
        printf(" %-10s                 %3d\n",to_chinese(poison_name[i]),me->query("poison_bag/"+poison_name[i]));
        return 1;
}
 
int query_autoload()
{
    if(environment())
    if(userp(environment()) && environment()->query("class") == "poisoner")
        return 1;
        return 0;
}

