#include "accountcombobox.h"
#include "accountitem.h"

AccountComboBox::AccountComboBox(QWidget *parent)
    :QComboBox(parent)
{
    //可编辑
    setEditable(true);

    //列表视图
    listWidget = new QListWidget();
    setModel(listWidget->model());
    setView(listWidget);
}

//添加账号
void AccountComboBox::AddAccount(AccountItem *accountItem)
{
    //显示账号
    connect(accountItem,SIGNAL(ShowAccountSign(QString)),
            this,SLOT(OnShowAccount(QString)));
    //删除账号
    connect(accountItem,SIGNAL(RemoveAccountSign(QString)),
            this,SLOT(OnRemoveAccount(QString)));

    //创建QListWidgetItem对象，并将其加入相应列表内
    QListWidgetItem *item = new QListWidgetItem(listWidget);
    listWidget->setItemWidget(item,accountItem);
}

//显示预设账号
void AccountComboBox::OnShowAccount(QString account)
{
    //将选中的账号誊到账号栏里，隐藏后续帐号
    setEditText(account);
    hidePopup();
}

//删除预设账号
void AccountComboBox::OnRemoveAccount(QString account)
{
    hidePopup();
    //将选中的账号誊到预设列表里删去
    for(int i = 0; i < listWidget->count(); i++){
        //通过索引得到具体的项
        QListWidgetItem *item = listWidget->item(i);

        //通过具体的项强制转化为需要的部件
        AccountItem *accountItem = (AccountItem *)(listWidget->itemWidget(item));
        QString number = accountItem->GetAccountNumber();
        if(account == number){
            listWidget->takeItem(i);        //移除
            delete item;                    //手动释放
            break;
        }
    }
}

AccountComboBox::~AccountComboBox()
{

}
