'''
    ## Unfinished Project ##
    DEVELOPMENT IN PROGRESS
'''

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.preprocessing import LabelEncoder

import warnings

plt.style.use('fivethirtyeight')
colors=['#011f4b','#03396c','#005b96','#6497b1','#b3cde0']
sns.set_palette(sns.color_palette(colors))

## Loading Dataset
df = pd.read_csv('survey_lung_cancer.csv')
# print(df.head)

# Print shape of data
# print(df.shape)

## Analysis numeriacal columns
# print(df.describe())

# Check for null values
# print(df.isnull().sum())

# Check for duplicates in the dataset
# print('Duplicated:',df.duplicated().sum())

## Drop duplicates value
df.drop_duplicates(inplace=True)
# print(df.shape)

## Encoding LUNG_CANCER and GENDER column
encoder = LabelEncoder()
df['LUNG_CANCER']=encoder.fit_transform(df['LUNG_CANCER'])
df['GENDER']=encoder.fit_transform(df['GENDER'])
# print(df.head(15))

# Separating continuous and categorical columns
con_col = ['AGE']
cat_col=[]
for i in df.columns:
    if i!='AGE':
        cat_col.append(i)

## Visualizing AGE columns

warnings.filterwarnings('ignore')
fig,ax = plt.subplots(1,3,figsize=(20,6))
sns.distplot(df['AGE'],ax=ax[0])
sns.histplot(data =df,x='AGE',ax=ax[1],hue='LUNG_CANCER',kde=True)
sns.boxplot(x=df['LUNG_CANCER'],y=df['AGE'],ax=ax[2])
plt.suptitle("Visualizing AGE column",size=20)
plt.show()


## Heat map (Pearson's Similarity)
# plt.figure(figsize=(15,15))
# sns.heatmap(df.corr(),annot=True,linewidth=0.5,fmt='0.2f')
# plt.show()