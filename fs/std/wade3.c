inherit ROOM;


// 要能存檔的第一步：
inherit F_SAVE;

// 如不想存檔，要加 static 在最前面
mapping data=([]);

void create()
{
 set("short","考題三");
 set("long","簡單的電話簿，可以利用(add)來增加資料，
 如果你閒麻煩也可以直接用(ask)，當然也可以
 用(list)列出所有的資料。\n");

 // 第二步，可以不要，那第三步要改
 set("save_file", __DIR__);
 setup();
}

// 第三步，配合第二步，看一下就知道了
string query_save_file() { return query ("save_file"); }

void init()
{
 add_action("do_add","add");
 add_action("do_ask","ask");
 add_action("do_list","list");
}
int do_add(string str)
{
 string str1,str2;
 if(sscanf(str,"%s %s",str1,str2)!=2)
  return notify_fail("輸入格式錯誤\n"); 
 printf("%s : %s\n",str1,str2); printf("%s 資料加入完畢\n",str1); 
 data += ([str1:str2]);
  // 存檔第四步, 該存檔時就下底下的命令
  this_object()->save();
 return 1;
}
int do_ask(string str1)
{
 if(!data[str1]) return notify_fail("你的通訊錄中並無此人資料\n");
 printf("%s 的聯絡電話是 %s\n",str1,data[str1]);
 return 1;
}
int do_list()
{
 printf("通訊錄資料\n");
 printf(" %O \n",data);
 printf("總共有 %d 筆資料\n",sizeof(data));
 return 1;
}
  
