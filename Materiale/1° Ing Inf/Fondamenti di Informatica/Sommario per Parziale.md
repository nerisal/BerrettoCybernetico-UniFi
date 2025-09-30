# Lista delle produzioni:

>[!info]
>In generale η :: = n indica che posso sostituire η al posto di n
>
>Le parentesi **\[]** e **{}** e il simbolo **|** in **grassetto** indicano le parentesi del BNF

## \<expr>::=
- &\<var>
- \<var>
- (\<expr>)
- \<expr₁> \<op₂> \<expr₂>
- \<op₁> \<expr>
- ­⌐ \<expr>
- \<const>
- ++ \<var>
- \-- \<var>
- \<var> ++
- \<var> --
- \<var> = \<expr>
- \<var> \<op₂> = \<expr₂>
- \<expr₁> , \<expr₂>
- \<cast_type> \<expr>
- \<expr>(<actual_parameter_list>)
- \<expr> ? \<expr> : \<expr>

## \<actual_parameter_list>::=
- **\[** \<expr> **{** , \<expr> **} \]** 

>[!info]
>Per indicare il valore di una espressione si utilizza il simbolo Γ

## \<op₂>::=
- *Operazioni*
	- \+
	- \-
	- \*
	- \/
	- % *Modulo*
- *Confronti*
	- < 
	- <=
	- ==
	- !=
	- \>=
	- \>
- *Uguaglianze*
	- &&
	- ||
- *Operatori Bit-a-Bit*
	- &
	- |
	- \>>
	- <<

## \<op₁>::=
- !
- ~

# \<type>::=
- char
- **\[** unassigned **\]** **\[** short **|** long **\]** int
- float
- double
- void
- struct \<identifier>

>[!info] Priorità dei tipi
> double >> float >> long_ int >> int >> short_int >> char

# \<decl>::=
- \<identifier> (\<id>)
- \*\<decl>
- &\<decl>
- \<decl>\[\<const>]
- (\<decl>)
- \<decl>(\<formal_parameter_list>);


# \<declaration>::=
- \<type>\<decl>;
- \<type>\<decl>(\<formal_parameter_list>);


# \<formal_parameter_list>::=
- void
- \<type>\<decl> **{** , \<type> \<decl> **}**

# \<function_definition>::= 
- \<type>\<decl>(\<formal_parameter_list)
  {
	  **{** \<declaration> **}**
	\<statement>
  }

# \<statement>::=
- \<expr> ;
- \<statement> \<statement>
- {\<statement>}
- if(\<expr>) \<statement>
- if(\<expr>) \<statement₁> else \<statement₂>
- for(\<expr-init>); \<expr-guard>; \<expr-inc>) \<statement>
- while(\<expr-guard->) \<statement>
- do\<statement> while(\<expr-guard>);
- goto\<label>
- switch \<expr>  { **{** case<\const>: \<statement> **}** **\[** default : \<statement> **\]**}
- break;
- continue;

# \<program>::=
- \<function_definition>
- \<function_declaration>
- \<directive>
- typedef \<type> \<identifier>

# \<directive>::=
- \#include \<filename.h>
- \#define \<identifier>\<any>

# \<var>::=
- \<expr>\[\<expr>]
- \*\<expr>
- \<identifier>
- (\<var>)
- \<expr> --> \<identifier>
- \<var-s-> . \<identifier>

# \<cast_type>::=
- \<type>
- \<cast_type>*

# \<struct_def>::=
- struct \<identifier> { **{** \<var_declaration **}** };

