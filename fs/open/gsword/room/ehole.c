#include <room.h>

 inherit ROOM;

 void create()
{
      
        set("short", "岩穴");
        set("long", @LONG
這兒是巖穴的內部，在右邊的一角是一個略高的岩石平臺，上面還鋪了一些
稻草之類的東西，中間有一張石桌(table)。所有的擺設看起來就像是有人居住一般
不過在這種環境之下，即使真的有人在這居住，想必也是隱居的武林高人。
LONG
        );

set("item_desc",([
"table": " 一張見方的石桌"
]));
        set("exits", ([
"west":__DIR__"hole"
        ]) );
setup();

}
void init()
{
 add_action("do_search","search");
   add_action("do_practice","practice");
 }
 
 
 int do_search(string str)
 {
   object user;
   user=this_player();
   if( !user->query_temp("have_win",1))
     {
      write("你在找什麼??\n");
      return 1;
     }    
    if(str=="table")
    {
     write(" 你再仔細一看發現桌上有一行小字寫著逍遙子藏書於斯....\n");
     user->set_temp("have_search_table",1);
     }
   else if(str=="bed")
   {
      if(!user->query_temp("have_search_table",1))     
       write("你在找什麼??\n");
      else
      {
      write("你發現床後刻著草字如下 : 
     
             仙劍後三式劍譜....
     
      仙劍後三式式式性質不同 ,依個人天資而較適合某招
 
      第一招... 
      第二招...
      第三招...
                     
      
      附註:當年逍遙子就是因為強練後三式,而形成心魔放出了綠毛老祖危恕H間
      故將此祕笈毀去而刻於此,願後人能小心練之(practice)..\n");
      user->set_temp("can_study",1);
      }   
   }
  else
   write("你在找什麼??\n");
    
  return 1;   
  }      
 int do_practice(string str)
 {
  object user;
  user=this_player();
  if(user->query("get_sha_sp",1)){
  message_vision("你已經學會了\n",user);
  user->set("title","仙劍派一代劍俠");
    return 1;
                                 }
  else
  {
    if(!user->query_temp("can_study",1))
      return 0;
    else
     {
     message_vision("經過一陣苦練 ,你終於學會了完整的仙劍劍術 ,得到了後三招的招式\n",user);        
     user->set("get_sha_sp",1);
  user->set("title","仙劍派一代劍俠");
      return 1;
     }
  
  }  
 }  
