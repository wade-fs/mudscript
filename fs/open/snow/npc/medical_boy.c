// 改寫自賣火材的小女孩..:)/open/center/npc/vendor.c 
#include "/open/open.h" 
 
// inherit F_VENDOR; 
 
void create() 
{ 
        set_name("採藥的少年", ({ "medical boy", "boy" }) ); 
        set("gender", "男性" ); 
        set("age", 18); 
        set("long", @LONG 
這是一名皮膚囿黑的少年，看他那結實的肌肉，不難猜出他平日一定常在山 
中採藥。 
LONG); 
        set("attitude", "friendly"); 
        //以下這一行表示稱號
        set("rank_info/respect", "小兄弟"); 
        set("combat_exp", 4000); 
        //以下表示這位npc所要賣的東西
        // set("vendor_goods", ({
        //    CENTER_OBJ"torch", 
        //    CENTER_OBJ"torch",                   
        //    CENTER_OBJ"map", 
        //  }) ); 
        //   greeting_msg用於當有人走來這個房間時，npc所要說的話
/*      set("greeting_msg", ({ 
            "採藥郎說道: 遭了！師父交代的草藥要是不趕緊找到的話，回去一定被罵。\
n", 
            "聽說這做山上生長著一種吃了能延年益壽的「神仙草」。\n", 
                             }) ); 
*/
        set("chat_chance" , 5);
        set("chat_msg" , ({
           (: this_object() , "random_move" :),
           "採藥郎說道：最近這裡有怪物出沒，師父還叫我一個人上山採藥...\n",
           "採藥郎說道：唉！師父交代的草藥如果不快找到的話，回去一定又要挨罵。\n
",
           "採藥郎說道：聽說這山上生長著一種叫做「神仙草」的珍藥。\n",
                          }) );
        set("inquiry" , ([
            "藥草"    :    "師父要我找的藥草其實很簡單，不過今天運氣比較差，到現
在連一株都沒採到。\n",
            "草藥"    :    "師父要我找的藥草其實很簡單，不過今天運氣比較差，到現
在連一株都沒採到。\n",
            "神仙草"  :    "聽說這種藥草吃了之後，對練功的人有一定程度的幫助。\n
",
            "師父"    :    "我師父可厲害了，聽說他以前是一名御醫呢！",
                         ]) );
        setup(); 
        //以下這一行表示這位npc所要攜帶的東西
        carry_object(CENTER_OBJ"cloth1")->wear(); 
} 
/* 
int accept_object(object who, object ob) 
{ 

object me; 
       me = this_object(); 

    if (ob->value() == 0) 
  int accept_object(object who, object ob) 
  { 
  object me; 
         me = this_object(); 
    if (ob->value() == 0) 
   message_vision
     ("$N說道: $n，非常感謝你，不過我比較希望能快點找到師父要的東西!\n", 
                     me, who); 
    else 
   message_vision
     ("$N說道: 謝謝你，$n，我回去可以跟師父交代了。\n", 
                     me, who); 
    message_vision("少年說道: 我現在還想不起來要怎麼謝謝你，將來想到一定報答你
。\n", 
                     me, who); 
 
  return 1; 
}
*/ 
