#include "mainwindow.h"
#include "ui_mainwindow.h"


int input[9][9];
int output[9][9];
int input_value(int x, int y, int value)
{
 int i,j;
 // Scan horizontally and vertically
 for (i = 0; i < 9; i++) {
  if (value == output[i][y] || value == output[x][i])
{
 return 0;
    }
 }
 // Scan its own square
 if (x < 3)
 {
  if (y < 3)
 {
   for (i = 0; i < 3; i++)
 {
    for (j = 0; j < 3; j++)
 {
     if (value == output[i][j])
{

        return  0;
      }
    }
      }
  }
 else if (y < 6)
{
   for (i = 0; i < 3; i++)
 {
    for (j = 3; j < 6; j++)
 {
     if (value == output[i][j])
 {
        return  0;           }
    }
      }
  }
 else
 {
   for (i = 0; i < 3; i++)
 {
    for (j = 6; j < 9; j++)
 {
     if (value == output[i][j])
 {
        return  0;
      }
    }
      }
    }
 }
 else if (x < 6)
 {
  if (y < 3)
 {
   for (i = 3; i < 6; i++)
 {
    for (j = 0; j < 3; j++)
 {
     if (value == output[i][j])
 {
        return  0;
      }
    }
      }
  }
 else if (y < 6)
 {
   for (i = 3; i < 6; i++)
 {
    for (j = 3; j < 6; j++)
{
     if (value == output[i][j])
 {
        return  0;
      }
    }
      }
  }
 else
 {
   for (i = 3; i < 6; i++)
{
    for (j = 6; j < 9; j++)
{
     if (value == output[i][j])
 {
        return  0;
      }
    }
      }
    }
 }
 else
 {
  if (y < 3)
 {
   for (i = 6; i < 9; i++)
 {
    for (j = 0; j < 3; j++)
{
     if (value == output[i][j])
 {
        return  0;
      }
    }
      }
  }
else if (y < 6)
{
   for (i = 6; i < 9; i++)
{
    for (j = 3; j < 6; j++)
 {
     if (value == output[i][j])
 {
        return  0;
      }
    }
      }
  }
 else
 {
   for (i = 6; i < 9; i++)
 {
    for (j = 6; j < 9; j++)
{
     if (value == output[i][j])
 {
        return  0;
      }         }
      }
    }
 }
 return value;
}


int solve(int x, int y)
 {
 int temp,i,j;
 for(i=0;i<9;i++)
 for(j=0;j<9;j++)
 if(output[i][j]>9||output[i][j]<0)
 return 0;
 if (output[x][y] == 0)
{

  for (i = 1; i < 10; i++)
 {
   temp = input_value(x,y,i);
   if (temp > 0)
{
    output[x][y] = temp;

    if (x == 8 && y == 8)
 {
      return 1;
    }
 else if (x == 8)
 {
      if (solve(0,y+1)) return 1;
    }
else
{
      if (solve(x+1,y)) return 1 ;
    }
      }
    }
  if (i == 10)
 {
      if (output[x][y] !=  input[x][y]) output[x][y] = 0;
   return 0;
    }
 }
 else
 {
  if (x == 8 && y == 8)
{
   return 1;
  }
 else if (x == 8)
{
    if (solve(0,y+1)) return 1;
  }
 else
 {
   if (solve(x+1,y)) return 1;
    }
 }

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            QString str;
            QTableWidgetItem* itm = ui->tableWidget->item( i, j );
            if (itm)
            {
                str = itm->text();
                input[i][j]=str.toInt();
                output[i][j]=input[i][j];
            }
            else output[i][j]=input[i][j]=0;
        }
    }
    if(solve(0,0))
    {        ui->label->setText("YES");

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            QTableWidgetItem *itab;
                   itab = new QTableWidgetItem; // add this line
                   QString s = QString::number(output[i][j]);
                   itab->setText(s);
                   if(input[i][j]!=0)
                   {
                       itab->setForeground(QColor::fromRgb(255,0,0)); //make this item red.
                   }
                   ui->tableWidget->setItem(i, j, itab);
        }
    }
    }
    else ui->label->setText("NO");
    /*
     QTableWidgetItem *itab;
            itab = new QTableWidgetItem; // add this line
            QString s = QString::number(j);
            itab->setText(s);
            ui->tableWidget->setItem(i, j, itab);
     */


    //delete(itab);
}
