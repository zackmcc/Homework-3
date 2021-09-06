-- ECE532 HW3
-- Zackary McClamma
-- 14-Oct-2019

library ieee;
  use ieee.std_logic_1164.all;

entity homework3 is
  port
  (
			i_clk           : in  std_logic                    := 'X'; -- clk
			i_reset_n     : in  std_logic                    := 'X'; -- reset_n
			disp1      : out std_logic_vector(6 downto 0);       
			disp2      : out std_logic_vector(6 downto 0);        
			disp3     : out std_logic_vector(6 downto 0);        
			disp5      : out std_logic_vector(6 downto 0);        
			disp4      : out std_logic_vector(6 downto 0);        
			disp6      : out std_logic_vector(6 downto 0);        
			disp7      : out std_logic_vector(6 downto 0);        
			disp8      : out std_logic_vector(6 downto 0);        
			switch_pio : in std_logic_vector(7 downto 0)         

 
  );
end homework3;

architecture sch of homework3 is

  component hw3_cpu is
	port (
            clk_clk           : in  std_logic                    := 'X'; -- clk
            reset_reset_n     : in  std_logic                    := 'X'; -- reset_n
            disp1_export      : out std_logic_vector(6 downto 0);        -- export
            disp2_export      : out std_logic_vector(6 downto 0);        -- export
            disp3_export      : out std_logic_vector(6 downto 0);        -- export
            disp5_export      : out std_logic_vector(6 downto 0);        -- export
            disp4_export      : out std_logic_vector(6 downto 0);        -- export
            disp6_export      : out std_logic_vector(6 downto 0);        -- export
				disp7_export      : out std_logic_vector(6 downto 0);                    -- export
				disp8_export      : out std_logic_vector(6 downto 0);
            switch_pio_export : in std_logic_vector(7 downto 0)         -- export
        );
  end component hw3_cpu;
  
begin

    u0 : component hw3_cpu
        port map (
            clk_clk           => i_clk,           --        clk.clk
            reset_reset_n     => i_reset_n,     --      reset.reset_n
            disp1_export      => disp1,      --      disp1.export
            disp2_export      => disp2,      --      disp2.export
            disp3_export      => disp3,      --      disp3.export
            disp5_export      => disp5,      --      disp5.export
            disp4_export      => disp4,      --      disp4.export
            disp6_export      => disp6,      --      disp6.export
				disp7_export      => disp7,      --      disp4.export
            disp8_export      => disp8,      --      disp6.export
            switch_pio_export => switch_pio  -- switch_pio.export
        );
end sch;
