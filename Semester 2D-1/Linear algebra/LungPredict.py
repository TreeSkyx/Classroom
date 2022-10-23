import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.preprocessing import LabelEncoder

plt.style.use('fivethirtyeight')
colors=['#011f4b','#03396c','#005b96','#6497b1','#b3cde0']
sns.set_palette(sns.color_palette(colors))

## Loading Dataset
df = pd.read_csv('survey_lung_cancer.csv')

## Drop duplicates value
df.drop_duplicates(inplace=True)
print(df.shape)

## Encoding LUNG_CANCER and GENDER column (form str to 0,1)
encoder = LabelEncoder()
df['LUNG_CANCER']=encoder.fit_transform(df['LUNG_CANCER'])
df['GENDER']=encoder.fit_transform(df['GENDER'])
# print(df.head())