C     This File is Automatically generated by ALOHA 
C     The process calculated in this file is: 
C     Metric(1,4)*Metric(2,3) - Metric(1,2)*Metric(3,4)
C     
      SUBROUTINE VVVV3P1N_2(V1, V3, V4, COUP,V2)
      IMPLICIT NONE
      COMPLEX*16 CI
      PARAMETER (CI=(0D0,1D0))
      COMPLEX*16 COUP
      COMPLEX*16 TMP10
      COMPLEX*16 TMP11
      COMPLEX*16 V1(*)
      COMPLEX*16 V2(6)
      COMPLEX*16 V3(*)
      COMPLEX*16 V4(*)
      TMP10 = (V1(3)*V4(3)-V1(4)*V4(4)-V1(5)*V4(5)-V1(6)*V4(6))
      TMP11 = (V3(3)*V4(3)-V3(4)*V4(4)-V3(5)*V4(5)-V3(6)*V4(6))
      V2(3)= COUP*(-CI*(V3(3)*TMP10)+CI*(V1(3)*TMP11))
      V2(4)= COUP*(+CI*(V3(4)*TMP10)-CI*(V1(4)*TMP11))
      V2(5)= COUP*(+CI*(V3(5)*TMP10)-CI*(V1(5)*TMP11))
      V2(6)= COUP*(+CI*(V3(6)*TMP10)-CI*(V1(6)*TMP11))
      END

